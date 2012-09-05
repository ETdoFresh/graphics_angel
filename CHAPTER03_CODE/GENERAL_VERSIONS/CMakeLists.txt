set (CHAPTER03_CODE
	example3.1
	example3.2
	example3.6
	track)

set (GRAPHICS_PROGRAMS
	${CHAPTER03_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
