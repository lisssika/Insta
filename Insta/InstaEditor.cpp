#include "InstaEditor.h"

#include "Mouse.h"
#include "TrackBar.h"
#include "Editor.h"
#include "ImageScale.h"

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
	std::shared_ptr<cv::Mat> image_ = std::make_shared<cv::Mat>(original_image_);
	cv::imshow(window_name, original_image_);
	const TrackBar track_bar(window_name, "scale", 100, 200);
	int key = 0;
	int old_scale = 100;
	while (key != exit_key)
	{
		
		const int scale = track_bar.get();

		key = cv::waitKey(1) & 0xFF; // некрасиво
		if (old_scale!=scale)
		{
			old_scale = scale;
			std::unique_ptr<EditorCommand> cmd = std::make_unique<ImageScale>(image_, scale);
			editor_.addAndExecuteCommand(std::move(cmd));
		}		
		cv::imshow(window_name, *image_);
	}
}
