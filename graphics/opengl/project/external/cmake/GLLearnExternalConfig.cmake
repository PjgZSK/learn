# add friendly paltform definition
include(../../cmake/BuildPlatformDefine.cmake)

# set platform specific path
set(_path_prefix ${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/)
if(IOS)
    set(platform_name ios)
    set(platform_spec_path ios)
elseif(ANDROID)
    set(platform_name android)
    set(platform_spec_path android/${ANDROID_ABI})
elseif(WINDOWS)
    set(platform_name win32)
    set(platform_spec_path win32)
elseif(MACOSX)
    set(platform_name mac)
    set(platform_spec_path mac)
elseif(LINUX)
    set(platform_name linux)
    set(platform_spec_path linux/64-bit)
endif()

set(platform_spec_path "${_path_prefix}${platform_spec_path}")
