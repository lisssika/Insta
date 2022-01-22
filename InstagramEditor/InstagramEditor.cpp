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
		return false; // cv::waitKey(1) == exit_key;
	}
	const int& min(const int& a, const int& b) {
		if (a < b)
			return a;
		return b;
	}
	enum Buttons
	{
		next = 27, //39,
		previous = 37
	};
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
			std::unique_ptr<EditorCommand> cmd = std::make_unique<CropCmd>(image, new_center, new_size);
			center_of_crop = new_center;
			size = new_size;
			editor_.execute(cmd);
		}
		catch (std::exception&)
		{
			std::unique_ptr<EditorCommand> cmd = std::make_unique<CropCmd>(image, center_of_crop, size);
			editor_.execute(cmd);
		}
		{
			int button = cv::waitKey(1);
			switch (button)
			{
				case Buttons::previous:
					filter.set_previous( 50);
					break;
				case Buttons::next:
					filter.set_next( 50);
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
