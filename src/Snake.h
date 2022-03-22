#pragma once

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "Segment.h"


class Snake
{
public:
	Snake(int init_field_size, int init_window_height, int init_window_width, sf::RenderWindow* init_window);
	~Snake();

	void move();
	void change_direction(int new_direction);

	int get_head_pos_x();
	int get_head_pos_y();

	void draw();

	void grow();



private:

	int field_size;
	int window_height;
	int window_width;

	int square_size;

	std::list<Segment> snake;

	sf::RenderWindow* window;

};