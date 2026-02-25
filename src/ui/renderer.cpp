#include <ncurses.h>
#ifdef NCURSES_WIDECHAR
#warning Wide mode active
#endif

#include "renderer.h"

#include <ncursesw/ncurses.h>
#include <locale.h>
#include <algorithm>
#include <vector>

renderer::renderer(int height, int width)
	: height_(height), width_(width)
{
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	timeout(0);
}

renderer::~renderer() {
	endwin();
}

void renderer::draw(const std::vector<double>& data) {
	clear();

	box(stdscr, 0, 0);

	if (data.empty()) {
		mvprintw(1, 2, "Waiting for data. . .");
		refresh();
		return;
	}

	double min_val = *std::min_element(data.begin(), data.end());
	double max_val = *std::max_element(data.begin(), data.end());

	double range = max_val - min_val;
	if (range == 0.0) range = 1.0;

	int graph_height = height_ - 2;
	int graph_width = std::min((int)data.size(), width_ - 2);

	for (int x = 0; x < graph_width; ++x) {
		double value = data[data.size() - graph_width + x];

		double normalized = (value - min_val) / range;
		int bar_height = static_cast<int>(normalized * graph_height);

		for (int y = 0; y < bar_height; ++y) {
			mvaddwstr(height_ - 2 - y, 1 + x, L"\u2588"); 
		}
	}

	mvprintw(0, 2, " Crypto Sparkline ");
	mvprintw(height_ - 1, 2, "Min: %.2f Max: %.2f", min_val, max_val);

	mvprintw(height_, 2, "Diff: %.2f", data[0] - data[1]);

	refresh();
}
