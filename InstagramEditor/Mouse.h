#pragma once
#include <string>
#include "Point.h"

class Mouse final
{
private:
	Point lbutton_down_coordinate_;
	Point lbutton_up_coordinate_;
	Point move_coordinate_;
	bool pressed = false;
public:
	Mouse(const std::string& window_name);
	void set_lbutton_down_coordinate(const Point& coord);
	void set_lbutton_up_coordinate(const Point& coord);
	void set_move_coordinate(const Point& coord);

	bool is_mouse_pressed() const;
	void set_mouse_down();
	void set_mouse_up();
	Point get_vector_offset_pressed() const;
};


