#pragma once

#include <iterator>
#include <vector>

class renderer {
	int height_;
	int width_;

public:
	renderer(int height, int width);
	~renderer();

	void draw(const std::vector<double>& data);
};
