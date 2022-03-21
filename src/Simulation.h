#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Field.h"


class Simulation
{
public:

	//Constructor
	Simulation(int map_size, int width, int height, std::string title);
	~Simulation();


	//Update
	void update();

	//Render
	void render();

	//helper
	bool is_open();




protected:

	std::shared_ptr<sf::RenderWindow> window;
	sf::Event event;

	Field field;
};

