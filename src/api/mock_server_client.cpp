#include "mock_server_client.h"

#include <cstddef>
#include <curl/curl.h>
#include <curl/easy.h>

#include <iterator>
#include <nlohmann/json.hpp>
#include <iostream>
#include <optional>
#include <system_error>

using json = nlohmann::json;

namespace {
	size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
		size_t total_size = size * nmemb;
		std::string* buffer = static_cast<std::string*>(userp);
		buffer->append(static_cast<char*>(contents), total_size);

		return total_size;
	}
}

mock_server_client::mock_server_client() {
	curl_global_init(CURL_GLOBAL_DEFAULT);
}
mock_server_client::~mock_server_client() {
	std::cout << "~mock_server_client()" << std::endl;
}

std::string mock_server_client::perform_request(const std::string& url) {
	CURL* curl = curl_easy_init();
	std::string response;

	if (!curl) {
		return "";
	}

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "crypto-tracker/1.0");

	CURLcode res = curl_easy_perform(curl);

	if (res != CURLE_OK) {
		std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
		curl_easy_cleanup(curl);
		return "";
	}

	curl_easy_cleanup(curl);
	return response;
}

std::optional<double> mock_server_client::fetch_price(
		const std::string& coinid_,
		const std::string& vscurrency_)
{
	std::string url = "http://localhost:8080/price";

	std::string response = perform_request(url);

	if (response.empty()) {
		return std::nullopt;
	}

	try {
		json j = json::parse(response);
		if (!j.contains(coinid_) || !j[coinid_].contains(vscurrency_)) {
			return std::nullopt;
		}

		return j[coinid_][vscurrency_].get<double>();
	}
	catch (const std::exception& e) {
		std::cerr << "JSON parse error: "
			<< e.what() << std::endl;
		return std::nullopt;
	}
}
