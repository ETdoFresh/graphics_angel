set (CHAPTER08_CODE
	example8.1
	example8.2
	example8.3 )

set (GRAPHICS_PROGRAMS
	${CHAPTER08_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
