#include "Snake.h"

Snake::Snake(int init_field_size, std::vector<std::vector<int>>* init_matrix) :
	field_size(init_field_size), matrix(init_matrix)
{
	this->snake.push_back(Segment(int(this->field_size / 2), int(this->field_size / 2), 1));
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
		if (this->snake.begin()->get_pos_x() + 1 >= field_size)
			this->snake.begin()->set_pos_x(0);
		else
			this->snake.begin()->set_pos_x(this->snake.begin()->get_pos_x() + 1);
	}
	else if (this->snake.begin()->get_direction() == 1)
	{
		if (this->snake.begin()->get_pos_y() - 1 < 0)
			this->snake.begin()->set_pos_y(this->field_size - 1);
		else
			this->snake.begin()->set_pos_y(this->snake.begin()->get_pos_y() - 1);
	}
	else if (this->snake.begin()->get_direction() == 2)
	{
		if (this->snake.begin()->get_pos_x() - 1 < 0)
			this->snake.begin()->set_pos_x(this->field_size - 1);
		else
			this->snake.begin()->set_pos_x(this->snake.begin()->get_pos_x() - 1);
	}
	else if (this->snake.begin()->get_direction() == 3)
	{
		if (this->snake.begin()->get_pos_y() + 1 >= this->field_size)
			this->snake.begin()->set_pos_y(0);
		else
			this->snake.begin()->set_pos_y(this->snake.begin()->get_pos_y() + 1);
	}
	this->matrix->at(this->snake.back().get_pos_y()).at(this->snake.back().get_pos_x()) = 0;
	
	for (std::list<Segment>::iterator it = this->snake.begin(); it != this->snake.end(); it++)
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

int Snake::update()
{
	int flag = 0;

	if (this->matrix->at(this->snake.begin()->get_pos_y()).at(snake.begin()->get_pos_x()) == 1)
	{
		return 2;
	}

	for (auto snake_segment : snake)
	{
		if (this->matrix->at(snake_segment.get_pos_y()).at(snake_segment.get_pos_x()) == 2)
		{
			this->grow();
			flag = 1;
		}
		
		this->matrix->at(snake_segment.get_pos_y()).at(snake_segment.get_pos_x()) = 1;
	}

	return flag;
}

void Snake::grow()
{
	int new_pos_x = this->snake.back().get_pos_x();
	int new_pos_y = this->snake.back().get_pos_y() + (1);
	int new_direction = this->snake.back().get_direction();

	this->snake.push_back(Segment(new_pos_x, new_pos_y, new_direction));
}
