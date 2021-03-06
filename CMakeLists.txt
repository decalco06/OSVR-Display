#
# OSVR-Display is a library and set of utilities
# that can detect displays (monitors) and set their
# properties (e.g., resolution, orientation)
#

cmake_minimum_required(VERSION 3.1.0)
project(osvrDisplay)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(UseBackportedModules)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Detect available C++ language, library, and compiler features
#
include(WriteCompilerDetectionHeader)
write_compiler_detection_header(
	FILE "${CMAKE_CURRENT_SOURCE_DIR}/osvr/Display/DisplayDefines.h"
	PREFIX OSVR_DISPLAY
	COMPILERS GNU Clang AppleClang MSVC
	FEATURES cxx_override cxx_noexcept cxx_constexpr
)

include(EnableExtraCompilerWarnings)
globally_enable_extra_compiler_warnings()

#
# Options
#
option(OSVR_DISPLAY_BUILD_APPS "Build applications that use osvrDisplay." ON)
option(OSVR_DISPLAY_BUILD_TESTS "Build test programs and unit tests." ON)

#
# Dependencies
#
find_package(osvr REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#
# Check Visual Studio version
#
set(HAVE_DOCOPT TRUE)
if(MSVC)
	include(GetMSVCVersion)
	get_msvc_major_version(_vs_major)
	if("${_vs_major}" LESS "15")
		set(HAVE_DOCOPT FALSE)
	endif()
endif()

#
# Third-party libraries
#
add_subdirectory(vendor)


#
# Default installation directories
#

include(GNUInstallDirs)


add_subdirectory(osvr/Display)

if(OSVR_DISPLAY_BUILD_APPS)
	add_subdirectory(apps)
endif()

include(CTest)
if(OSVR_DISPLAY_BUILD_TESTS)
	add_subdirectory(test)
endif()

