#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation.h"

int main() 
{
	Simulation game(20, 1000, 1000, "Snake Game");

	while (game.is_open())
	{
		game.update();
		if(game.is_open()) game.render();
	}

	return 0;
}
