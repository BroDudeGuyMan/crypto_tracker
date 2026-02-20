add_library(renderer)
target_sources(renderer
	PRIVATE
	 renderer.cpp
	
	 PUBLIC
	  FILE_SET HEADERS
	  FILES
	   renderer.h
)
