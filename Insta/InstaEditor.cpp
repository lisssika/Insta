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

namespace 
{
	std::string window_name("Insta Image Editor");
	int exit_key = 27;
}

InstaEditor::InstaEditor(const cv::Mat& image):original_image_(image)
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
	std::shared_ptr<cv::Mat> image_ = std::make_shared<cv::Mat>(original_image_);
	cv::imshow(window_name, original_image_);
	Mouse mouse(window_name);

	const TrackBar track_bar(window_name, "scale", 100, 200);
	Point image_center(image_->cols / 2, image_->rows / 2);
	ImageCropper cropper(500, image_center);
	int key = 0;
	int old_scale = 100;
	while (key != exit_key)
	{
		
		const int scale = track_bar.get();

		key = cv::waitKey(1); // некрасиво
		if (old_scale!=scale)
		{
			old_scale = scale;
			original_image_.copyTo(*image_);
			std::unique_ptr<EditorCommand> cmd = std::make_unique<ResizeCmd>(image_, scale);
			editor_.addAndExecuteCommand(std::move(cmd));
		}
		if (!mouse.is_mouse_pressed())
		{
			image_center = Point{ image_->cols / 2, image_->rows / 2 } + mouse.get_vector_offset_pressed();
		}
		else
		{
			image_center = Point{ image_->cols / 2, image_->rows / 2 };
		}
		cropper.set_new_center(image_center);
		*image_ = cropper.transform(*image_);
		cv::imshow(window_name, *image_);
	}
}
