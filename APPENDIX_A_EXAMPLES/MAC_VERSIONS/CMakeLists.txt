set (APPENDIX_CODE
	append_example_a10
	append_example_a2
	append_example_a3
	append_example_a4
	append_example_a5
	append_example_a6
	append_example_a7
	append_example_a8
	append_example_a9 )

set (GRAPHICS_PROGRAMS
	${APPENDIX_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
