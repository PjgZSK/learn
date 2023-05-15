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
#include <windows.h>
#include <tchar.h>
#define main() WINAPI \
				_tWinMain(HINSTANCE hInstance, \
                       HINSTANCE hPrevInstance, \
                       LPTSTR    lpCmdLine, \
                       int       nCmdShow) 
#else
#define main() main()
#endif

#endif /*__PLATFORM_DEFINE_H__*/
