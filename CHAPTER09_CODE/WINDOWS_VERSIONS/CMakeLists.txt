set (CHAPTER09_CODE
	example9.1
	example9.2 )

set (GRAPHICS_PROGRAMS
	${CHAPTER09_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
