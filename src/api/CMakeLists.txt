add_library(coin_gecko_client)
add_library(mock_server_client)
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)
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
	 nlohmann_json::nlohmann_json
)

target_sources(mock_server_client
	PRIVATE
	 mock_server_client.cpp

	PUBLIC
	 FILE_SET HEADERS
	 FILES
	  mock_server_client.h
)
