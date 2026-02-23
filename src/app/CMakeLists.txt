add_library(application)
target_sources(application
	PRIVATE
	 application.cpp

	PUBLIC
	 FILE_SET HEADERS
	 FILES
	  application.h
)
target_link_libraries(application
	PUBLIC
	 coin_gecko_client
	 mock_server_client
	 price_buffer
	 renderer
)
