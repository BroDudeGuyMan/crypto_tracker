add_library(coin_gecko_client)
find_package(CURL REQUIRED)
target_sources(coin_gecko_client
	PRIVATE
	 coin_gecko_client.cpp

	PUBLIC
	 FILE_SET HEADERS
	 FILES
	  coin_gecko_client.h
)

target_link_libraries(coin_gecko_client
	PRIVATE
	 CURL::libcurl
)
