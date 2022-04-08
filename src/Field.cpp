#include "Field.h"

Field::Field(int init_field_size, int init_window_height, int init_window_width, sf::RenderWindow* init_window) :
	field_size(init_field_size),
	window_height(init_window_height), 
	window_width(init_window_width), 
	window(init_window),
	apple(Apple((int)(field_size / 2), (int)(field_size / 2), field_size, this->get_matrix())), 
	snake(init_field_size, this->get_matrix())
{
	this->init_matrix();
	this->snake = Snake(field_size, this->get_matrix());
	this->apple = Apple((int)(field_size / 2), (int)(field_size / 2), field_size, this->get_matrix());
	
	this->matrix->at((int)(field_size / 2)).at((int)(field_size / 2)) = 2;
}

Field::~Field()
{

}

void Field::update_apple()
{
	this->apple.reinit();
}

void Field::update_snake(int new_direction)
{
	this->snake.change_direction(new_direction);
}

void Field::update_move()
{
	this->snake.move();
	
	int reset_flag = this->snake.update();

	if (reset_flag == 1) this->update_apple();
	else if (reset_flag == 2) this->window->close();
}

void Field::init_matrix()
{


	std::vector<int> temp_vector;

	this->matrix = std::make_shared<std::vector<std::vector<int>>>();

	for (int i = 0; i < this->field_size; i++)
	{
		temp_vector.push_back(0);
	}

	for (int i = 0; i < this->field_size; i++)
	{
		this->matrix.get()->push_back(temp_vector);
	}
}

std::vector<std::vector<int>>* Field::get_matrix()
{
	return this->matrix.get();
}

void Field::draw()
{
	sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(this->window_width / this->field_size-2.f, this->window_height / this->field_size-2.f));
	this->apple_shape = sf::CircleShape(this->window_width / this->field_size / 2);
	

	int row_counter = 0;
	int col_counter = 0;

	for (auto row : *matrix)
	{
		col_counter = 0;
		for (auto col : row)
		{
			if(col == 1) square.setFillColor(sf::Color::Green);
			else if(col == 0) square.setFillColor(sf::Color::Black);

			square.setPosition(sf::Vector2f(col_counter * this->window_width / this->field_size+1.f, row_counter * this->window_height / this->field_size+1.f));
			this->window->draw(square);

			if (col == 2)
			{
				apple_shape.setPosition(sf::Vector2f(this->apple.get_pos_x() * this->window_width / this->field_size, this->apple.get_pos_y() * this->window_height / this->field_size));
				apple_shape.setFillColor(sf::Color::Red);
				this->window->draw(apple_shape);
			}

			col_counter++;
		}
		row_counter++;
	}
}
