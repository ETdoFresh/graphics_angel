set (CHAPTER10_CODE
	example10.1
	example10.2
	example10.3
	example10.4 )

set (GRAPHICS_PROGRAMS
	${CHAPTER10_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
