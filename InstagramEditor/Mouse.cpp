#include "Mouse.h"
#include "Point.h"
#include <opencv2/highgui.hpp>

void new_mouse_coordinates(int mouse_event, int mouseX, int mouseY, int, void* mouse)
{
	const auto mouse_x = static_cast<int>(mouseX);
	const auto mouse_y = static_cast<int>(mouseY);
	Mouse mouse_ = *static_cast<Mouse*>(mouse);
	switch (mouse_event)
	{
	case cv::EVENT_MOUSEMOVE:
		static_cast<Mouse*>(mouse)->set_move_coordinate(Point{ mouse_x, mouse_y });
		break;
	case cv::EVENT_LBUTTONDOWN:
		static_cast<Mouse*>(mouse)->set_mouse_down();
		static_cast<Mouse*>(mouse)->set_lbutton_down_coordinate(Point{ mouse_x, mouse_y });
		break;
	case cv::EVENT_LBUTTONUP:
		static_cast<Mouse*>(mouse)->set_mouse_up();
		static_cast<Mouse*>(mouse)->set_lbutton_up_coordinate(Point{ mouse_x, mouse_y });
		break;
	default:
		break;
	}
}

Mouse::Mouse(const std::string& window_name)
{
	cv::setMouseCallback(window_name, new_mouse_coordinates, this);
}

void Mouse::set_move_coordinate(const Point& coord)
{
	modern_coordinate_ = coord;
}


void Mouse::set_lbutton_down_coordinate(const Point& coord)
{
	lbutton_down_coordinate_ = coord;
}

void Mouse::set_lbutton_up_coordinate(const Point& coord)
{
	lbutton_up_coordinate_ = coord;
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

Point Mouse::get_vector_offset_pressed() 
{
	if (pressed)
	{
		Point offset = modern_coordinate_ - old_pressed_point_;
		old_pressed_point_ = modern_coordinate_;
		return offset;
	}
	return Point{ 0, 0 };
}
