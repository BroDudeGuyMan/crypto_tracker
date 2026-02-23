#include "application.h"

#include <coin_gecko_client.h>
#include <mock_server_client.h>
#include <price_buffer.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <csignal>

std::atomic<bool> running{true};
void signal_handler(int) {
	running = false;
}


application::application() = default;
application::~application() = default;

int application::run() {
	std::cout << "Starting application::run(). . ." << std::endl;

	std::signal(SIGINT, signal_handler);

	//coin_gecko_client client;
	mock_server_client client;

	using clock = std::chrono::steady_clock;
	auto next_tick = clock::now();

	const std::chrono::seconds interval(1);

	price_buffer buffer(30);

	while (running) {
		next_tick += interval;

		auto price = client.fetch_price("bitcoin", "usd");

		if (price) {
			buffer.add(*price);
			std::cout << "BTC-USD: $" << *price << std::endl;
		} else {
			std::cout << "Failed to fetch price" << std::endl;
		}

		std::this_thread::sleep_until(next_tick);
	}

	std::cout << "Exiting. . ." << std::endl;

	return 0;
}
