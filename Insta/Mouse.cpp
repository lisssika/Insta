#include "Mouse.h"
#include "Point.h"
#include <opencv2/highgui.hpp>

void new_mouse_coordinates(int mouse_event, int mouseX, int mouseY, int, void* mouse)
{
	Mouse mouse_ = *static_cast<Mouse*>(mouse);
	switch (mouse_event)
	{
	case cv::EVENT_LBUTTONDOWN:
		static_cast<Mouse*>(mouse)->set_mouse_down();
		static_cast<Mouse*>(mouse)->set_lbutton_down_coordinate(Point{ mouseX, mouseY });
		break;
	case cv::EVENT_LBUTTONUP:
		static_cast<Mouse*>(mouse)->set_mouse_up();
		static_cast<Mouse*>(mouse)->set_lbutton_up_coordinate(Point{ mouseX, mouseY });
		break;
	default:
		break;
	}
}

Mouse::Mouse(const std::string& window_name_)
{
	cv::setMouseCallback(window_name_, new_mouse_coordinates, this);
}

void Mouse::operator()(int x, int y, bool flg)
{
	x_ = x;
	y_ = y;
	was_moved = flg;
}

void Mouse::set_lbutton_down_coordinate(const Point& coord)
{
	lbutton_down_coordinate_ = coord;
}

void Mouse::set_lbutton_up_coordinate(const Point& coord)
{
	lbutton_up_coordinate_ = coord;
}

int Mouse::get_x() const
{
	return x_;
}

int Mouse::get_y() const
{
	return y_;
}

bool Mouse::moved() const
{
	return was_moved;
}

void Mouse::reset_moved()
{
	was_moved = false;
}

void Mouse::set_mouse_down()
{
	pressed = true;
}

void Mouse::set_mouse_up()
{
	pressed = false;
}

bool Mouse::is_mouse_pressed() const
{
	return pressed;
}

Point Mouse::get_vector_offset_pressed() const
{
	//if (lbutton_up_coordinate_ - lbutton_down_coordinate_ != Point(0, 0))
	//{
		//int a = 1;
	//}
	return lbutton_up_coordinate_ - lbutton_down_coordinate_;
}
