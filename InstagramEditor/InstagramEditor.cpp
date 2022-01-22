#include "InstagramEditor.h"
#include "Window.h"
#include "Mouse.h"
#include <string>
#include <opencv2/highgui.hpp>
#include "EditorCommand.h"
#include "CropCmd.h"
#include "Point.h"

namespace 
{
	const std::string window_name{"Instagram Editor"};
	const int window_size = 500;
	int exit_key = 27;
	void check_exit(bool& exit) {
		if (cv::waitKey(1) == exit_key)
		{
			exit_key = true;
		}
		exit_key = false;
		//exit_key = cv::waitKey(1) == exit_key;
	}
	const int& min(const int& a, const int& b) {
		if (a < b)
			return a;
		return b;
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
	bool exit = false;
	auto image = std::make_shared<cv::Mat>();
	image_->copyTo(*image);
	const int width = image->cols;
	const int height = image->rows;
	Point center_of_crop = Point{ width / 2, height / 2 };
	int size = min(width, height);
	Point offset;
	while (!exit)
	{
		image_->copyTo(*image);
		check_exit(exit); // мб это прям в условие можно вынести
		try
		{
			offset = mouse.get_vector_offset_pressed();
			Point new_center = center_of_crop - offset;
			std::unique_ptr<EditorCommand> cmd = std::make_unique<CropCmd>(image, new_center, size);
			center_of_crop = new_center;
			editor_.execute(cmd);

		}
		catch (std::exception&)
		{
			std::unique_ptr<EditorCommand> cmd = std::make_unique<CropCmd>(image, center_of_crop, size);
			editor_.execute(cmd);
		}
		window_.show(*image);
	}
}
