/*************************************************************************
    > File Name: platform_config.h
    > Author: pjg
    > Mail: 
    > Created Time: 2023/5/5 11:59:34
 ************************************************************************/

#ifndef __PLATFORM_CONFIG_H__
#define __PLATFORM_CONFIG_H__

#define PLATFORM_UNKNOW     0 
#define PLATFORM_WIN32      1
#define PLATFORM_MAC        2
#define PLATFORM_IOS        3

#define TARGET_PLATFORM PLATFORM_UNKNOW



// Apple: Mac and iOS
#if defined(__APPLE__) && !defined(ANDROID) // exclude android for binding generator.
    #include <TargetConditionals.h>
    #if TARGET_OS_IPHONE // TARGET_OS_IPHONE includes TARGET_OS_IOS TARGET_OS_TV and TARGET_OS_WATCH. see TargetConditionals.h
        #undef  TARGET_PLATFORM
        #define TARGET_PLATFORM         PLATFORM_IOS
    #elif TARGET_OS_MAC
        #undef  TARGET_PLATFORM
        #define TARGET_PLATFORM         PLATFORM_MAC
    #endif
#endif

// win32
#if defined(_WIN32) && defined(_WINDOWS)
    #undef  TARGET_PLATFORM
    #define TARGET_PLATFORM         PLATFORM_WIN32
#endif



#endif /*__PLATFORM_CONFIG_H__*/
