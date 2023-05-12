/*************************************************************************
    > File Name: log.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2023/5/12 17:42:46
 ************************************************************************/
#include "log.h"
#include <stdio.h>
#include <stdarg.h>
#include <new>
#include <algorithm>
#include "src/platform/platform_config.h"
#include <windows.h>

void log(const char * format, ...)
{
    int bufferSize = MAX_LOG_LENGTH;
    char* buf = nullptr;
    int nret = 0;
    va_list args;
    do
    {
        buf = new (std::nothrow) char[bufferSize];
        if (buf == nullptr)
            return;
        /*
        pitfall: The behavior of vsnprintf between VS2013 and VS2015/2017 is different
        VS2013 or Unix-Like System will return -1 when buffer not enough, but VS2015/2017 will return the actural needed length for buffer at this station
        The _vsnprintf behavior is compatible API which always return -1 when buffer isn't enough at VS2013/2015/2017
        Yes, The vsnprintf is more efficient implemented by MSVC 19.0 or later, AND it's also standard-compliant, see reference: http://www.cplusplus.com/reference/cstdio/vsnprintf/
        */
        va_start(args, format);
        nret = vsnprintf(buf, bufferSize - 3, format, args);
        va_end(args);

        if (nret >= 0)
        { // VS2015/2017
            if (nret <= bufferSize - 3)
            {// success, so don't need to realloc
                break;
            }
            else
            {
                bufferSize = nret + 3;
                delete[] buf;
            }
        }
        else // < 0
        {	// VS2013 or Unix-like System(GCC)
            bufferSize *= 2;
            delete[] buf;
        }
    } while (true);
#if TARGET_PLATFORM != PLATFORM_WIN32
    buf[nret] = '\n';
    buf[++nret] = '\0';
#else
    buf[nret] = '\0';
#endif

#if TARGET_PLATFORM ==  PLATFORM_WIN32

    int pos = 0;
    int len = nret;
    char* tempBuf[MAX_LOG_LENGTH + 1] = { 0 };

    do
    {
        int dataSize = std::min(MAX_LOG_LENGTH, len - pos);
        std::copy(buf + pos, buf + pos + dataSize, tempBuf);

		tempBuf[dataSize] = 0;

        OutputDebugString(tempBuf);
        OutputDebugString("\n");
        pos += dataSize;

    } while (pos < len);
#else
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", buf);
    fflush(stdout);
#endif

    delete[] buf;
}
