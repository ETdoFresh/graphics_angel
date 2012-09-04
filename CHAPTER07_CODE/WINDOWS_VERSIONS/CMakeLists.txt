set (CHAPTER07_CODE
	example7.1
	example7.2
	example7.3 )

set (GRAPHICS_PROGRAMS
	${CHAPTER07_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
