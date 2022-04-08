#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Apple.h"
#include "Snake.h"

class Field
{
public:

    //Constructor
    Field(int init_field_size, int init_window_height, int init_window_width, sf::RenderWindow* init_window);
    ~Field();


    void update_apple();

    void update_snake(int new_direction);

    void update_move();

    void init_matrix();

    std::vector<std::vector<int>>* get_matrix();

    void draw();

    
private:

    std::shared_ptr<std::vector<std::vector<int>>> matrix;

    sf::RenderWindow* window;

    const int field_size;
    const int window_width;
    const int window_height;

    Apple apple;
    Snake snake;

    sf::CircleShape apple_shape;

};

