#include "Snake.h"

Snake::Snake(int init_field_size, int init_window_height, int init_window_width, sf::RenderWindow* init_window) :
	field_size(init_field_size), window_height(init_window_height), window_width(init_window_width), window(init_window), square_size(window_height / field_size)
{
	this->snake.push_back(Segment(int(this->window_width / 2), int(this->window_height / 2), 1));
	this->grow();
	this->grow();
	this->grow();
	this->grow();
	this->grow();
	this->grow();
}

Snake::~Snake()
{
}

void Snake::move()
{
	int counter = 0;

	int new_pos_x = this->snake.begin()->get_pos_x();
	int new_pos_y = this->snake.begin()->get_pos_y();
	int new_direction = this->snake.begin()->get_direction();

	if (this->snake.begin()->get_direction() == 0)
	{
		if(this->snake.begin()->get_pos_x() + this->square_size >= this->window_width) 
			this->snake.begin()->set_pos_x(0);
		else 
			this->snake.begin()->set_pos_x(this->snake.begin()->get_pos_x() + this->square_size);
	}
	else if (this->snake.begin()->get_direction() == 1)
	{
		if(this->snake.begin()->get_pos_y() - this->square_size < 0) 
			this->snake.begin()->set_pos_y(this->window_height - this->square_size);
		else 
			this->snake.begin()->set_pos_y(this->snake.begin()->get_pos_y() - this->square_size);
	}
	else if (this->snake.begin()->get_direction() == 2)
	{
		if(this->snake.begin()->get_pos_x() - this->square_size < 0)
			this->snake.begin()->set_pos_x(this->window_width - this->square_size);
		else 
			this->snake.begin()->set_pos_x(this->snake.begin()->get_pos_x() - this->square_size);
	}
	else if (this->snake.begin()->get_direction() == 3)
	{
		if(this->snake.begin()->get_pos_y() + this->square_size >= this->window_height)
			this->snake.begin()->set_pos_y(0);
		else 
			this->snake.begin()->set_pos_y(this->snake.begin()->get_pos_y() + this->square_size);
	}

	//for (auto& segment : this->snake)
	for(std::list<Segment>::iterator it = this->snake.begin(); it != this->snake.end();it++)
	{
		if (it == this->snake.begin()) continue;

		int old_direction = (*it).get_direction();
		int old_pos_x = (*it).get_pos_x();
		int old_pos_y = (*it).get_pos_y();
		
		(*it).set_direction(new_direction);
		(*it).set_pos_x(new_pos_x);
		(*it).set_pos_y(new_pos_y);

		new_direction = old_direction;
		new_pos_x = old_pos_x;
		new_pos_y = old_pos_y;
	}
}

void Snake::change_direction(int new_direction)
{	
	if (abs(this->snake.begin()->get_direction() - new_direction) == 2) return;
	this->snake.begin()->set_direction(new_direction);
}

int Snake::get_head_pos_x()
{
	return this->snake.begin()->get_pos_x();
}

int Snake::get_head_pos_y()
{
	return snake.begin()->get_pos_y();
}

void Snake::draw()
{
	sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(square_size - 2.f, square_size - 2.f));
	square.setFillColor(sf::Color::Green);

	for (auto snake_segment : snake)
	{
		square.setPosition(sf::Vector2f(snake_segment.get_pos_x(), snake_segment.get_pos_y()));
		this->window->draw(square);
	}
}

void Snake::grow()
{
	int new_pos_x = this->snake.back().get_pos_x();
	int new_pos_y = this->snake.back().get_pos_y() + (this->square_size);
	int new_direction = this->snake.back().get_direction();

	this->snake.push_back(Segment(new_pos_x, new_pos_y, new_direction));
}
