#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>
#include <string>
#include "Point.h"

// можно сделать шаблонным классом, если точка задана int, то это пиксели, а если double<1 то это относительный размер...

Point::Point(int x, int y) :x_(x), y_(y) {}
Point::Point() : x_{ 0 }, y_{ 0 }{}

Point Point::operator+(Point const& p) const {
	return{ x_ + p.x_, y_ + p.y_ };
}
Point Point::operator-(Point const& p) const {
	return{ x_ - p.x_, y_ - p.y_ };
}
Point Point::operator*(int a) const {
	return { x_ * a, y_ * a };
}

void Point::scale(int sx, int sy)
{
	x_ *= sx;
	y_ *= sy;
}

std::string Point::to_string() const
{
	return to_string(x_) + " " + to_string(y_);
}

int Point::get_x() const
{
	return x_;
}

int Point::get_y() const
{
	return y_;
}

bool Point::operator==(Point const& point) const
{
	return x_==point.x_ && y_ == point.y_;
}

bool Point::operator!=(const Point& point) const
{
	return !operator==(point);
}

std::string Point::to_string(int number) const
{
	std::string number_str = std::to_string(number);
	for (int i = number_str.size(); i > 0; i--)
	{
		if (number_str[i] == '0')
		{
			number_str.pop_back();
		}
		if (number_str[i] == '.')
		{
			return number_str;
		}
	}
	return std::to_string(number);
}
