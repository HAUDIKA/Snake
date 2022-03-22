#pragma once 

class Segment
{
public:
	Segment(int init_pos_x, int init_pos_y, int init_direction);


	int get_pos_x();
	int get_pos_y();
	int get_direction();

	void set_pos_x(int new_pos_x);
	void set_pos_y(int new_pos_y);
	void set_direction(int new_direction);

private:
	int pos_x;
	int pos_y;
	int direction;
};