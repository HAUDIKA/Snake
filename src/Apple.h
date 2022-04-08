#pragma once

#include <iostream>
#include <random>
#include "SFML/Graphics.hpp"

class Apple
{
public:

	Apple(int init_pos_x, int init_pos_y, int init_field_size, std::vector<std::vector<int>>* init_matrix);

	int get_pos_x();
	int get_pos_y();

	void reinit();
	sf::CircleShape draw();

private:
	int pos_x;
	int pos_y;

	int field_size;

	std::vector<std::vector<int>>* matrix;
};