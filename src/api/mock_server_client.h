#pragma once

#include <string>
#include <optional>

class mock_server_client {
	std::string perform_request(const std::string& url);

public:
	mock_server_client();
	~mock_server_client();

	std::optional<double> fetch_price(
			const std::string& coinid_,
			const std::string& vscurrency_
	);

	void log_response();
};
