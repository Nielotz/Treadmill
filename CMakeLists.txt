cmake_minimum_required(VERSION 3.13)

project(TreadmillHack CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Check which platform we're building for
set(PLATFORM "linux_test" CACHE STRING "Build platform: pico2w or linux_test")
set_property(CACHE PLATFORM PROPERTY STRINGS "pico2w" "linux_test")

if(PLATFORM STREQUAL "pico2w")
    # Pico-specific configuration
    # Initialise pico_sdk from installed location
    # (note this can come from environment, CMake cache etc)

    # == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
    if(WIN32)
        set(USERHOME $ENV{USERPROFILE})
    else()
        set(USERHOME $ENV{HOME})
    endif()
    set(sdkVersion 2.1.1)
    set(toolchainVersion 14_2_Rel1)
    set(picotoolVersion 2.1.1)
    set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
    if (EXISTS ${picoVscode})
        include(${picoVscode})
    endif()
    # ====================================================================================
    set(PICO_BOARD pico2_w CACHE STRING "Board type")

    # Pull in Raspberry Pi Pico SDK (must be before project)
    include(pico_sdk_import.cmake)

    project(TreadmillHack C CXX ASM)

    # Initialise the Raspberry Pi Pico SDK
    pico_sdk_init()

    # Add executable. Default name is the project name, version 0.1
    add_executable(TreadmillHack src/main.cpp)

    pico_set_program_name(TreadmillHack "TreadmillHack")
    pico_set_program_version(TreadmillHack "0.1")

    # Modify the below lines to enable/disable output over UART/USB
    pico_enable_stdio_uart(TreadmillHack 0)
    pico_enable_stdio_usb(TreadmillHack 1)

    # Add the standard library to the build
    target_link_libraries(TreadmillHack
            pico_stdlib)

    # Add any user requested libraries
    target_link_libraries(TreadmillHack 
            hardware_i2c
            hardware_watchdog
            pico_cyw43_arch_none
            )

    # Set platform define for Pico
    target_compile_definitions(TreadmillHack PRIVATE PLATFORM_PICO)

    pico_add_extra_outputs(TreadmillHack)
elseif(PLATFORM STREQUAL "linux_test")
    message(STATUS "Building Linux test platform")

    add_executable(all_tests
        test/simple_io_test.cpp
        # test/another_test.cpp
    )
    target_compile_definitions(all_tests PRIVATE PLATFORM_LINUX_TEST)

    target_include_directories(all_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/src/platform/linux_test
        ${CMAKE_SOURCE_DIR}/src
    )

    # Prefer a locally cached/vendor'ed Catch2, otherwise fetch into a persistent folder
    set(CATCH2_LOCAL_DIR "${CMAKE_SOURCE_DIR}/third_party/Catch2" CACHE PATH "Path to local Catch2 source")
    if(EXISTS "${CATCH2_LOCAL_DIR}/CMakeLists.txt")
        message(STATUS "Using local Catch2 at ${CATCH2_LOCAL_DIR}")
        add_subdirectory("${CATCH2_LOCAL_DIR}" _deps/Catch2)
    else()
        find_package(Catch2 3 QUIET)
        if(NOT Catch2_FOUND)
            message(STATUS "Catch2 not found via find_package; fetching into a persistent cache (.deps)")
            include(FetchContent)
            # Keep fetched content across builds to avoid re-downloading
            set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/.deps" CACHE PATH "Base dir for FetchContent" FORCE)
            set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "Do not auto-update fetched content" FORCE)

            FetchContent_Declare(
                Catch2
                GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                GIT_TAG        v3.10.0
            )
            FetchContent_MakeAvailable(Catch2)
        else()
            message(STATUS "Found Catch2 locally: ${Catch2_DIR}")
        endif()
    endif()

    if(TARGET Catch2::Catch2WithMain)
        message(STATUS "Successfully fetched Catch2: Catch2::Catch2WithMain target is available")
    else()
        message(FATAL_ERROR "Failed to fetch Catch2 or Catch2::Catch2WithMain target not available")
    endif()
    target_link_libraries(all_tests PRIVATE Catch2::Catch2WithMain)
endif()

