#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <stdexcept>
#include "ImageWindow.h"
#include "Mouse.h"
#include "LocalBlur.h"
#include "TrackBar.h"

ImageWindow::ImageWindow(const cv::Mat& image, std::string const& window_name) :window_name_(window_name)
{
	if (image.empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	image.copyTo(original_image_);
}

void ImageWindow::init()
{

	cv::imshow(window_name_, original_image_);
	int initial_side_ = 250;
	int max_side_ = 500;
	track_bar = std::make_unique<TrackBar>(window_name_, "side of blur rect", initial_side_, max_side_);
	mouse = std::make_unique<Mouse>(window_name_);
	const std::shared_ptr<BlurMethod> blur_method = std::make_shared<GaussBlur>();
	blur = std::make_unique<LocalBlur>(blur_method);
}

void ImageWindow::draw()
{
	init();
	int key = 0;
	while (key != exit_key_)
	{
		const int side_blur_region = track_bar->get();
		LocalBlurParams blur_params(mouse->get_x(), mouse->get_y(), side_blur_region, side_blur_region);
		
		cv::Mat image;// = original_image_;
		if (!mouse->moved())
		{
			image = blur->get_blur_image(original_image_, blur_params);
		}
		else
		{
			image = original_image_;
		}
		
		cv::imshow(window_name_, image);
		key = cv::waitKey(1) & 0xFF;
		mouse->reset_moved();
	}
}


