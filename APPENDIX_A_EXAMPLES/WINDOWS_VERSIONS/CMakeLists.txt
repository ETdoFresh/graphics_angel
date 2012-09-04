set (APPENDIX_CODE
	append_example10
	append_example2
	append_example3
	append_example4
	append_example5
	append_example6
	append_example7
	append_example8
	append_example9 )

set (GRAPHICS_PROGRAMS
	${APPENDIX_CODE} )

if (GRAPHICS_COMPLETE)
  foreach(program ${GRAPHICS_PROGRAMS})
    add_executable(${program} ${program}.cpp)
    target_link_libraries(${program} ${ALL_LIBS} )
  endforeach(program)
endif ()
