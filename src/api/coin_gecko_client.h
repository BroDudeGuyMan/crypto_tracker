#pragma once

#include <string>
#include <optional>

class coin_gecko_client {
	std::string perform_request(const std::string& url);

public:
	coin_gecko_client();
	~coin_gecko_client();

	std::optional<double> fetch_price(
			const std::string& coinid_,
			const std::string& vscurrency_
	);

	void log_response();
};
