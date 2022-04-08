#pragma once

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "Segment.h"


class Snake
{
public:
	Snake(int init_field_size, std::vector<std::vector<int>>* init_matrix);
	~Snake();

	void move();
	void change_direction(int new_direction);

	int get_head_pos_x();
	int get_head_pos_y();

	int update();

	void grow();



private:

	int field_size;

	std::list<Segment> snake;

	std::vector<std::vector<int>>* matrix;

};