set (CHAPTER05_CODE
	example5.1
	example5.2
	example5.3
	example5.6 )

set (GRAPHICS_PROGRAMS
	${CHAPTER05_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
