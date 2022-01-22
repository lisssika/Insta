#pragma once
#include <string>
#include "TrackBar.h"
#include "Mouse.h"
#include <memory>

class Window
{
public:
	Window(const std::string& name, int width, int height);
private:
	std::unique_ptr<Mouse> mouse;
	//std::unique_ptr<ShowStrategy> show // как назвать?
};
