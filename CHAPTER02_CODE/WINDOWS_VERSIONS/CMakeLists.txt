set (CHAPTER02_CODE
	example2.1
	example2.2
	example2.3
	example2.4
	example2.4b
	example2.5)

set (GRAPHICS_PROGRAMS
	${CHAPTER02_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
