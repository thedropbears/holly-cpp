cmake_minimum_required(VERSION 2.8)
include(FRCDeploy)

project(Holly)
find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS} lib .)

macro (add_sources)
    file (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SOURCE_CODE "${_relPath}/${_src}")
        else()
            list (APPEND SOURCE_CODE "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate SOURCE_CODE to parent directory
        set (SOURCE_CODE ${SOURCE_CODE} PARENT_SCOPE)
    endif()
endmacro()

add_sources(Holly.cpp
  OI.cpp
  CommandBase.cpp
)
add_subdirectory(commands)
add_subdirectory(subsystems)
add_subdirectory(lib)

add_executable(Holly ${SOURCE_CODE})
target_link_libraries(Holly ${WPILib_LIBRARY} lib-4774)

add_make_deploy(Holly 10.47.74.2) # where your team number is xxyy
