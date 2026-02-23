#pragma once

#include <vector>
#include <optional>

class price_buffer {
	std::vector<double> buffer_;
	std::size_t capacity_;
	std::size_t head_ = 0;
	std::size_t count_ = 0;

public:
	explicit price_buffer(std::size_t capacity);

	void add(double pice);

	std::vector<double> get_data() const;

	std::optional<double> min() const;
	std::optional<double> max() const;

	bool empty() const;
	std::size_t size() const;
};

