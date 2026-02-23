find_package(Curses REQUIRED)
add_library(renderer)
target_sources(renderer
	PRIVATE
	 renderer.cpp
	
	 PUBLIC
	  FILE_SET HEADERS
	  FILES
	   renderer.h
)
target_link_libraries(renderer
	PRIVATE
	 ${CURSES_LIBRARIES}
 )

 target_include_directories(renderer
	 PRIVATE
	  ${CURSES_INCLUDE_DIR}
)
