/*************************************************************************
    > File Name: platform_define.h
    > Author: pjg
    > Mail: 
    > Created Time: 2023/5/12 16:04:34
 ************************************************************************/

#ifndef __PLATFORM_DEFINE_H__
#define __PLATFORM_DEFINE_H__


#include "platform_config.h"

#if TARGET_PLATFORM == PLATFORM_WIN32
#define main() WINAPI _tWinMain(HINSTANCE hInstance, \
                       HINSTANCE hPrevInstance, \
                       LPTSTR    lpCmdLine, \
                       int       nCmdShow)
#else
#define main() main()
#endif

#if TARGET_PLATFORM == PLATFORM_WIN32
#include <windows.h>
#define log(s) OutputDebugString(s)
#else
#define log(s) std::cout << s << std::endl;
#endif


#endif /*__PLATFORM_DEFINE_H__*/
