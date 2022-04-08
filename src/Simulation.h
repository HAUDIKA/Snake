#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <random>

#include "Field.h"
#include "Snake.h"
#include "Apple.h"


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

	int field_size;
	int window_height;
	int window_width;

	Field field;

	

	double time_intervall = 0.01;
	double measured_time = 0;
	std::clock_t start;


};

