cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(caffe_register)


set(CMAKE_BUILD_TYPE Release)

# The MSVC compiler stipulates that the release and debug modes cannot be mixed. Here, by changing
# the compilation and link options, the source code can also be debugged in the release mode.
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    if(ENABLE_DEBUG)
        add_compile_options(/Zi /Od)
        add_link_options(/DEBUG)
    endif()
endif()

# platform specifics
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
endif()

# eliminate warning: warning C4819, http://t.zoukankan.com/Chary-p-13608011.html
# You can add the compile option: "-Xcompiler "/wd 4819" " to eliminate the warning (warning C4819)
if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()


if(MSVC)
    # Parallel make.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
endif()

# Report
message(STATUS " =================================================")
message(STATUS " project source dir: "  ${PROJECT_SOURCE_DIR})
message(STATUS " project binary dir: "  ${PROJECT_BINARY_DIR})
message(STATUS " System: "              ${CMAKE_SYSTEM_NAME})
message(STATUS " Architecture: "        ${CMAKE_SYSTEM_PROCESSOR})
message(STATUS " C Compiler: "          ${CMAKE_C_COMPILER})
message(STATUS " C++ Compiler: "        ${CMAKE_CXX_COMPILER})
message(STATUS " CUDA Compiler: "       ${CMAKE_CUDA_COMPILER})
if(MSVC)
    message(STATUS " Linker flags (Release): " ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_RELEASE})
else()
    message(STATUS " Linker flags (Release): " ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS_RELEASE})
endif()
message(STATUS " =================================================")


# If GNUInstallDirs is not included, CMAKE_INSTALL_BINDIR is empty.
include(GNUInstallDirs)

# it must go before project in order to work
set(CMAKE_INSTALL_PREFIX  "${PROJECT_SOURCE_DIR}" CACHE PATH "Installation Directory" FORCE)

# third source code path
set(THIRDPARTY_SOURCE_DIR   "${PROJECT_SOURCE_DIR}/3rdparty" CACHE STRING "Third party libraries source directories.")
# third file compile path: build/3rdparty
set(THIRDPARTY_BINARY_DIR   "${PROJECT_BINARY_DIR}/3rdparty" CACHE STRING "Third party libraries build directories.")
# third file install path
set(THIRDPARTY_INSTALL_DIR  "${PROJECT_BINARY_DIR}/3rdparty/install" CACHE STRING "Third party libraries install directories.")
# include(${THIRDPARTY_SOURCE_DIR}/3rdparty.cmake)

# include source files
add_subdirectory(src)
