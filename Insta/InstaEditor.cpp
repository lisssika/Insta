#include "InstaEditor.h"
#include "Point.h"
#include "Mouse.h"
#include "TrackBar.h"
#include "Editor.h"
#include "ResizeCmd.h"
#include <opencv2/core/core_c.h>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include "ImageCropper.h"
#include "SqrCroppCmd.h"

namespace 
{
	std::string window_name("Insta Image Editor");
	int exit_key = 27;
}

InstaEditor::InstaEditor(const cv::Mat& image)
{
	if (image.empty())
	{
		throw std::runtime_error("Image Not Found!");
	}
	image.copyTo(original_image_);
}

void InstaEditor::execute()
{
	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE | cv::WINDOW_GUI_EXPANDED);
	cv::namedWindow("settings", cv::WINDOW_AUTOSIZE | cv::WINDOW_GUI_EXPANDED);
	image_ = std::make_shared<cv::Mat>(original_image_);
	cv::imshow(window_name, original_image_);

	const Mouse mouse(window_name);
	const TrackBar track_bar(window_name, "scale", 100, 200);

	Point image_center(image_->cols / 2, image_->rows / 2);
	Point old_center(image_->cols / 2, image_->rows / 2);
	int key = 0;
	int old_scale = 100;
	while (key != exit_key)
	{
		original_image_.copyTo(*image_);
		const int scale = track_bar.get();

		key = cv::waitKey(1); 
		if (old_scale!=scale)
		{
			old_scale = scale;
			std::unique_ptr<EditorCommand> cmd = std::make_unique<ResizeCmd>(image_, scale);
			editor_.add_command(std::move(cmd));
		}
		image_center = image_center - mouse.get_vector_offset_pressed();
		std::unique_ptr<EditorCommand> cropp_cmd = std::make_unique<SqrCroppCmd>(image_, image_center, 500);
		editor_.add_command(std::move(cropp_cmd));
		try
		{
			editor_.apply_condition();
			old_center = image_center;
		}
		catch (std::runtime_error& )
		{
			editor_.undo();
			image_center = old_center;
		}
		cv::imshow(window_name, *image_);
	}
}
