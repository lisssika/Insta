#include "InstagramEditor.h"
#include "Window.h"
#include "Mouse.h"
#include <string>
#include <opencv2/highgui.hpp>
#include "EditorCommand.h"
#include "CropCmd.h"
#include "Point.h"
#include "TrackBar.h"
#include "ImageFilter.h"
namespace 
{
	const std::string window_name{"Instagram Editor"};
	const int window_size = 500;
	int exit_key = 27;
	bool check_exit() {
		return cv::waitKey(1) == exit_key;
	}
	const int& min(const int& a, const int& b) {
		if (a < b)
			return a;
		return b;
	}
	enum Buttons
	{
		next = 49,
		previous = 50 
	};
	void validate_center(Point& center,  int size, int cols, int rows)
	{
		if (size>min(cols, rows))
		{
			throw std::runtime_error("The area is larger the image. \n");
		}
		const int half_size = size / 2;
		if (center.get_x()< half_size)
		{
			center += Point{ half_size - center.get_x(), 0 };
		}
		if (center.get_x() + half_size > cols)
		{
			center -= Point{ center.get_x() + half_size - cols, 0 };
		}
		if (center.get_y() < half_size)
		{
			center += Point{ 0, half_size - center.get_y() };
		}
		if (center.get_y() + half_size > rows)
		{
			center -= Point{0, center.get_y() + half_size - rows };
		}
	}
}

InstagramEditor::InstagramEditor(const cv::Mat& image)
{
	image.copyTo(original_image_);
	image_ = std::make_shared<cv::Mat>(original_image_);
}

void InstagramEditor::execute()
{
	Window window_{ window_name, window_size, window_size };
	Mouse mouse(window_name);
	TrackBar zoom(window_name, "zoom", 100, 100);
	TrackBar filter_intensity(window_name, "intensity", 50, 100);
	

	bool exit = false;
	auto image = std::make_shared<cv::Mat>();
	image_->copyTo(*image);
	const int width = image->cols;
	const int height = image->rows;
	Point center_of_crop = Point{ width / 2, height / 2 };
	const int orig_size = min(width, height);
	int size = orig_size;

	ImageFilter filter;//убрать в команду
	filter.set_next(50);

	while (!check_exit())
	{
		image_->copyTo(*image);
		try
		{
			Point offset = mouse.get_vector_offset_pressed();
			Point new_center = center_of_crop - offset;
			int new_size = zoom.get() * orig_size/100;
			validate_center(new_center, new_size, image->cols, image->rows);
			std::unique_ptr<EditorCommand> cmd = std::make_unique<CropCmd>(image, new_center, new_size);
			center_of_crop = new_center;
			size = new_size;
			editor_.execute(cmd);
		}
		catch (std::runtime_error&)
		{
			std::unique_ptr<EditorCommand> cmd = std::make_unique<CropCmd>(image, center_of_crop, size);
			editor_.execute(cmd);
		}

		{
			int intensity = filter_intensity.get();
			int button = cv::waitKey(1);
			switch (button)
			{
				case Buttons::previous:
					filter.set_previous(intensity);
					break;
				case Buttons::next:
					filter.set_next(intensity);
					break;
				default:
					break;
			}
			filter.set_image(*image);
			*image = filter.transform();
		}
		window_.show(*image);
	}
}
