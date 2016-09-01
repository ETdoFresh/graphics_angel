cmake_minimum_required (VERSION 2.6)
project (angelcode)
# The version number.
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)
# set(CMAKE_CXX_FLAGS "-g -Wall -pedantic -fno-inline -Wno-deprecated -Wpointer-arith -Wcast-qual -Wcast-align -DEXCEPTIONS_VERBOSE")
set(CMAKE_CXX_FLAGS "-g2")
# #set(CMAKE_CXX_FLAGS "-O3")
# following sets the variables OPENGL_INCLUDE_DIR amd OPENGL_LIBRARIES
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")
find_package(OpenGL)
# following sets the variables GLUT_INCLUDE_DIR amd GLUT_LIBRARIES
if (NOT WIN32)
 find_package(GLUT)
else ()
 find_package(LOCAL_GLUT)
endif ()

IF (NOT APPLE)
	find_package(GLEW)
ENDIF ()

set (GRAPHICS_COMPLETE FALSE)
if (APPLE)
  if (OPENGL_FOUND AND GLUT_FOUND)
    set (GRAPHICS_COMPLETE TRUE)
    set (EXTERNAL_GRAPHICS_INCLUDES
        ${OPENGL_INCLUDE_DIR} 
        ${GLUT_INCLUDE_DIR}
        )
  endif ()
else ()
  #i.e. not apple
  if (OPENGL_FOUND AND GLUT_FOUND AND GLEW_FOUND)
    set(GRAPHICS_COMPLETE TRUE)
    set (EXTERNAL_GRAPHICS_INCLUDES
        ${OPENGL_INCLUDE_DIR} 
        ${GLUT_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        )
  else ()
    if (NOT OPENGL_FOUND)
          MESSAGE (STATUS "OPENGL and/or OPENGL-development subsystems not found - please install")
    endif ()

    if (NOT GLUT_FOUND)
          MESSAGE (STATUS "GLUT and/or GLUT-development subsystems not found - please install")
    endif ()
    if (NOT GLUT_Xmu_LIBRARY)
          MESSAGE (STATUS "GLUT Xmu and/or GLUT Xmu development subsystems not found - please install")
    endif ()
    if (NOT GLUT_Xi_LIBRARY)
          MESSAGE (STATUS "GLUT Xi and/or GLUT Xi development subsystems not found - please install")
    endif()
    if (NOT GLEW_FOUND)
          MESSAGE (STATUS "GLEW and/or GLEW development subsystems not found - please install")
    endif()
  endif ()
endif ()

if (GRAPHICS_COMPLETE)
	 ADD_DEFINITIONS("-DHAVE_OPENGL")
endif ()

set(GRAPHICSLIBS
        ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARIES}
        ${GLEW_LIBRARIES}
    )

if (NOT APPLE AND NOT WIN32 AND GRAPHICS_COMPLETE)
	ADD_DEFINITIONS("-DGLEW_EXPERIMENTAL")
endif ()

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

#if (APPLE)
#	set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/shaders/MAC_VERSIONS)
#else ()
#	set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/shaders/WINDOWS_VERSIONS)
#endif ()

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

subdirs( CHAPTER02_CODE 
		CHAPTER03_CODE 
		CHAPTER04_CODE 
		CHAPTER05_CODE 
		CHAPTER07_CODE 
		CHAPTER08_CODE 
		CHAPTER09_CODE 
		CHAPTER10_CODE
		APPENDIX_A_EXAMPLES )
	
