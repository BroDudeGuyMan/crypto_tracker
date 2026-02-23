#include "price_buffer.h"

#include <algorithm>

price_buffer::price_buffer(std::size_t capacity)
	: buffer_(capacity), capacity_(capacity) {}

void price_buffer::add(double price) {
	buffer_[head_] = price;
	head_ = (head_ + 1) % capacity_;

	if (count_ < capacity_) {
		++count_;
	}
}

std::vector<double> price_buffer::get_data() const {
	std::vector<double> result;
	result.reserve(count_);

	for (std::size_t i = 0; i < count_; ++i) {
		std::size_t index = (head_ + capacity_ - count_ + i) % capacity_;
		result.push_back(buffer_[index]);
	}

	return result;
}

std::optional<double> price_buffer::min() const {
	if (empty()) return std::nullopt;

	auto data = get_data();
	return *std::min_element(data.begin(), data.end());
}

std::optional<double> price_buffer::max() const {
	if (empty()) return std::nullopt;

	auto data = get_data();
	return *std::max_element(data.begin(), data.end());
}

bool price_buffer::empty() const {
	return count_ == 0;
}

std::size_t price_buffer::size() const {
	return count_;
}
