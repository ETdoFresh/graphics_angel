set (CHAPTER04_CODE
	example4.1
	example4.2
	example4.3 )

set (GRAPHICS_PROGRAMS
	${CHAPTER04_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
