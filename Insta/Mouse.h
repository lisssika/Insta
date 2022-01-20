#pragma once
#include <string>
#include "Point.h"

class Mouse final
{
private:
	int x_ = 0;
	int y_ = 0;
	bool was_moved = false;
	Point lbutton_down_coordinate_;
	Point lbutton_up_coordinate_;
	bool pressed;
public:
	Mouse(const std::string& window_name_);
	void operator()(int x, int y, bool flg);
	void set_lbutton_down_coordinate(const Point& coord);
	void set_lbutton_up_coordinate(const Point& coord);

	int get_x() const;
	int get_y() const;
	bool moved() const;
	void reset_moved();
	bool is_mouse_pressed() const;
	void set_mouse_down();
	void set_mouse_up();
	Point get_vector_offset_pressed() const;
};

