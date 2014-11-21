cmake_minimum_required (VERSION 2.6)

find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS} .)

add_definitions ("-Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-value ")

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

AUX_SOURCE_DIRECTORY(auton AutonSources)
AUX_SOURCE_DIRECTORY(pid PidSources)
AUX_SOURCE_DIRECTORY(systems SystemsSources)
AUX_SOURCE_DIRECTORY(vision VisionSources)

add_sources(
  ${AutonSources}
  ${PidSources}
  ${SystemsSources}
  ${VisionSources}
)
