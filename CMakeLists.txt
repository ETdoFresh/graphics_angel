cmake_minimum_required (VERSION 2.6)
project (angelcode)
# The version number.
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)
# set(CMAKE_CXX_FLAGS "-g -Wall -pedantic -fno-inline -Wno-deprecated -Wpointer-arith -Wcast-qual -Wcast-align -DEXCEPTIONS_VERBOSE")
# #set(CMAKE_CXX_FLAGS "-g2")
# #set(CMAKE_CXX_FLAGS "-O3")
# following sets the variables OPENGL_INCLUDE_DIR amd OPENGL_LIBRARIES
find_package(OpenGL)
# following sets the variables GLUT_INCLUDE_DIR amd GLUT_LIBRARIES
find_package(GLUT)

IF (NOT APPLE)
	find_package(GLEW)
ENDIF ()

set (GRAPHICS_COMPLETE NO)
if (APPLE)
  if (OPENGL_FOUND AND GLUT_FOUND)
    set (GRAPHICS_COMPLETE yes)
    set (EXTERNAL_GRAPHICS_INCLUDES
        ${OPENGL_INCLUDE_DIR} 
        ${GLUT_INCLUDE_DIR}
        )
  endif ()
else ()
  #i.e. not apple
  if (OPENGL_FOUND AND GLUT_FOUND AND GLUT_Xmu_LIBRARY AND GLUT_Xi_LIBRARY AND GLEW_FOUND)
    set(GRAPHICS_COMPLETE yes)
    set (EXTERNAL_GRAPHICS_INCLUDES
        ${OPENGL_INCLUDE_DIR} 
        ${GLUT_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        )
  endif ()
endif ()

if (GRAPHICS_COMPLETE)
	 ADD_DEFINITIONS("-DHAVE_OPENGL")
endif ()

set(GRAPHICSLIBS
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARIES}
        ${GLEW_LIBRARY}
    )

MESSAGE (STATUS "All graphics subsystems needed are present? " ${GRAPHICS_COMPLETE})

set (BASE_INCLUDES  ./include )

if (GRAPHICS_COMPLETE)
    set (BASE_INCLUDES ${BASE_INCLUDES}
        ${EXTERNAL_GRAPHICS_INCLUDES} )
endif ()

MESSAGE (STATUS "Using include: "
        ${BASE_INCLUDES})

include_directories (${BASE_INCLUDES})

set (COMMON
        Common/InitShader.cpp
    )

add_library (angel_common  ${COMMON} )

set (ALL_LIBS angel_common ${GRAPHICSLIBS})

subdirs( CHAPTER02_CODE 
		CHAPTER03_CODE 
		CHAPTER04_CODE 
		CHAPTER05_CODE 
		CHAPTER07_CODE 
		CHAPTER08_CODE 
		CHAPTER09_CODE 
		CHAPTER10_CODE
		APPENDIX_A_EXAMPLES )
	
