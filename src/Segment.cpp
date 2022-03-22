#include "Segment.h"

Segment::Segment(int init_pos_x, int init_pos_y, int init_direction):
	pos_x(init_pos_x), pos_y(init_pos_y), direction(init_direction)
{

}

int Segment::get_pos_x()
{
	return this->pos_x;
}

int Segment::get_pos_y()
{
	return this->pos_y;
}

int Segment::get_direction()
{
	return this->direction;
}

void Segment::set_pos_x(int new_pos_x)
{
	this->pos_x = new_pos_x;
}

void Segment::set_pos_y(int new_pos_y)
{
	this->pos_y = new_pos_y;
}

void Segment::set_direction(int new_direction)
{
	this->direction = new_direction;
}