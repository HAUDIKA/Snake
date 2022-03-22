#include "Apple.h"

Apple::Apple(int init_pos_x, int init_pos_y, int init_square_size, int init_window_size, int init_field_size) :
	pos_x(init_pos_x), pos_y(init_pos_y), square_size(init_square_size), window_size(init_window_size), field_size(init_field_size)
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
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, window_size/square_size-1); // distribution in range [1, 6]

	this->pos_x = square_size * dist6(rng);
	this->pos_y = square_size * dist6(rng);
}

sf::CircleShape Apple::draw()
{
	auto apple = sf::CircleShape(this->square_size / 2);
	apple.setPosition(sf::Vector2f(pos_x, pos_y));
	apple.setFillColor(sf::Color::Red);
	return apple;
}
