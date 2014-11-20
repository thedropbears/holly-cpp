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

add_sources (
AutonomousCommandGroup.cpp
AutonTension.cpp
DriveForward.cpp
)
