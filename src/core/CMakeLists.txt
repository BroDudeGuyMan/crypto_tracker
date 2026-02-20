add_library(price_buffer)
target_sources(price_buffer
	PRIVATE
	 price_buffer.cpp

	PUBLIC
	 FILE_SET HEADERS
	 FILES
	  price_buffer.h
)
