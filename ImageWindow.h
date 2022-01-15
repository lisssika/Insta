#pragma once
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

#include "LocalBlur.h"
#include "Mouse.h"
#include "TrackBar.h"

class ImageWindow final
{
public:
	ImageWindow(const cv::Mat& image, std::string const& window_name);
	void draw();
	void init();
	void blur_near_stopped_mouse();
private:
	std::string window_name_;
	int exit_key_ = 27;
	cv::Mat original_image_;

	std::unique_ptr<LocalBlur> blur;
	std::shared_ptr<TrackBar> track_bar;
	std::unique_ptr<Mouse> mouse;
};

