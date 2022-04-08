#include "Apple.h"

Apple::Apple(int init_pos_x, int init_pos_y, int init_field_size, std::vector<std::vector<int>>* init_matrix) :
	pos_x(init_pos_x), pos_y(init_pos_y), field_size(init_field_size), matrix(init_matrix)
{
	
}

int Apple::get_pos_x()
{
	return this->pos_x;
}

int Apple::get_pos_y()
{
	return this->pos_y;
}

void Apple::reinit()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0,field_size-1);

	this->pos_x = dist6(rng);
	this->pos_y = dist6(rng);

	this->matrix->at(this->get_pos_y()).at(this->get_pos_x()) = 2;
}

