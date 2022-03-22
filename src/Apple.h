#pragma once

#include <iostream>
#include <random>
#include "SFML/Graphics.hpp"

class Apple
{
public:

	Apple(int init_pos_x, int init_pos_y, int init_square_size, int init_window_size, int init_field_size);

	int get_pos_x();
	int get_pos_y();

	void reinit();
	sf::CircleShape draw();

private:
	int pos_x;
	int pos_y;

	int field_size;
	int square_size;
	int window_size;
};