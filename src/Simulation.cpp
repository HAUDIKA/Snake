#include "Simulation.h"

Simulation::Simulation(int init_map_size, int init_width, int init_height, std::string init_title) :
	window(std::make_shared<sf::RenderWindow>(sf::VideoMode(init_width, init_height), init_title)), 
	event(sf::Event()), 
	field(init_map_size, init_height, init_width, this->window.get()),
	start(std::clock()), field_size(init_map_size),
	window_height(init_height), window_width(init_width)
{
	this->window->setFramerateLimit(15);
}

Simulation::~Simulation()
{
}

void Simulation::update()
{
	bool input_read = false;

	//Reading events
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
			return;
		}
		else if (this->event.type == sf::Event::KeyPressed && !input_read)
		{
			if (this->event.key.code == sf::Keyboard::Right) this->field.update_snake(0);
			if (this->event.key.code == sf::Keyboard::Up) this->field.update_snake(1);
			if (this->event.key.code == sf::Keyboard::Left) this->field.update_snake(2);
			if (this->event.key.code == sf::Keyboard::Down) this->field.update_snake(3);
			input_read = true;
		}
	}
	this->measured_time = (double)(std::clock() - this->start) / (double)CLOCKS_PER_SEC;
	if (this->measured_time - this->time_intervall > 0)
	{
		this->field.update_move();

		this->measured_time = 0;
		this->start = std::clock();
	}
}

void Simulation::render()
{
	this->window->clear(sf::Color::Blue);

	
	this->field.draw();

	this->window->display();
}

bool Simulation::is_open()
{
	return this->window->isOpen();
}


