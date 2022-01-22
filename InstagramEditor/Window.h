#pragma once
#include <string>
#include "TrackBar.h"
#include "Mouse.h"
#include <memory>
#include <opencv2/core/mat.hpp>

class Window
{
public:
	Window(const std::string& name, int width, int height);
	void show(const cv::Mat& image) const; // надо подумать, мб разумный указатель?
private:
	std::unique_ptr<Mouse> mouse;
	std::string name_;
	//std::unique_ptr<ShowStrategy> show // как назвать?
};
