#include "Field.h"

Field::Field(int init_field_size, int init_window_height, int init_window_width, sf::RenderWindow* init_window) :
	field_size(init_field_size), window_height(init_window_height), window_width(init_window_width), window(init_window)
{
	this->init_matrix();
}

Field::~Field()
{

}

void Field::update()
{
}

void Field::init_matrix()
{
	std::vector<int> temp_vector;

	for (int i = 0; i < this->field_size; i++)
	{
		temp_vector.push_back(0);
	}

	for (int i = 0; i < this->field_size; i++)
	{
		this->matrix.push_back(temp_vector);
	}
}

void Field::draw()
{
	sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(this->window_width / this->field_size-2.f, this->window_height / this->field_size-2.f));
	square.setFillColor(sf::Color::Black);
	

	int row_counter = 0;
	int col_counter = 0;

	for (auto row : this->matrix)
	{
		col_counter = 0;
		for (auto col : row)
		{

			square.setPosition(sf::Vector2f(col_counter * this->window_width / this->field_size+1.f, row_counter * this->window_height / this->field_size+1.f));
			this->window->draw(square);
			col_counter++;
		}
		row_counter++;
	}
}
