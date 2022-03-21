#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class Field
{
public:

    //Constructor
    Field(int init_field_size, int init_window_height, int init_window_width, sf::RenderWindow* init_window);
    ~Field();


    void update();

    void init_matrix();

    void draw();
    
private:

    std::vector<std::vector<int>> matrix;

    sf::RenderWindow* window;

    const int field_size;
    const int window_width;
    const int window_height;



};

