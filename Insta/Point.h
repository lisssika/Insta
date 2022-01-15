#pragma once
#include <ostream>
#include <string>

struct Point {
	Point(int x, int y);
	Point();
	Point operator+(Point const& p) const;
	Point operator-(Point const& p) const;
	Point operator*(int a) const;
	void scale(int sx, int sy);
	std::string to_string() const;
	int get_x() const;
	int get_y() const;
	bool operator==(Point const& p) const;

private:
	int x_;
	int y_;

	std::string to_string(int number) const;
};