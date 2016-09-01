#
# Try to find GLEW library and include path.
# Once done this will define
#
# GLEW_FOUND
# GLEW_INCLUDE_PATH
# GLEW_LIBRARY
# 

IF (WIN32)
	FIND_PATH( GLEW_INCLUDE_PATH GL/glew.h
	$ENV{PROGRAMFILES}/GLEW/include
	${PROJECT_SOURCE_DIR}/src/nvgl/glew/include
    ${CMAKE_SOURCE_DIR}/include
	DOC "The directory where GL/glew.h resides")
	FIND_LIBRARY( GLEW_LIBRARY
				NAMES glew GLEW glew32 glew32s
				PATHS
					$ENV{PROGRAMFILES}/GLEW/lib
					${PROJECT_SOURCE_DIR}/src/nvgl/glew/bin
					${PROJECT_SOURCE_DIR}/src/nvgl/glew/lib
                    ${CMAKE_SOURCE_DIR}/lib/windows
					DOC "The GLEW library")
	FIND_LIBRARY( GLEW_LIBRARY_DEBUG glew32d ${CMAKE_SOURCE_DIR}/lib/windows)
ELSE (WIN32)
	FIND_PATH( GLEW_INCLUDE_PATH GL/glew.h
 				/usr/include
				/usr/local/include
				/sw/include
				/opt/local/include
				DOC "The directory where GL/glew.h resides")
	FIND_LIBRARY( GLEW_LIBRARY
				NAMES GLEW glew
				PATHS
						/usr/lib64
						/usr/lib
						/usr/local/lib64
						/usr/local/lib
						/sw/lib
						/opt/local/lib
				DOC "The GLEW library")
ENDIF (WIN32)

	IF (GLEW_INCLUDE_PATH)
		SET( GLEW_FOUND 1 CACHE STRING "Set to 1 if GLEW is found, 0 otherwise")
	ELSE (GLEW_INCLUDE_PATH)
		SET( GLEW_FOUND 0 CACHE STRING "Set to 1 if GLEW is found, 0 otherwise")
	ENDIF (GLEW_INCLUDE_PATH)

	MARK_AS_ADVANCED( GLEW_FOUND )

IF (GLEW_FOUND)
  SET( GLEW_LIBRARIES
    ${GLEW_LIBRARY}
    ${GLEW_LIBRARY_DEBUG}
    )
ENDIF(GLEW_FOUND)