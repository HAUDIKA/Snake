#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation.h"

int main() 
{
	Simulation game(10, 1080, 1000, "Title");

	while (game.is_open())
	{
		game.update();
		if(game.is_open()) game.render();
	}

	return 0;
}
