#include "EditorCommand.h"
#include <typeinfo>

EditorCommand::EditorCommand(const std::shared_ptr<cv::Mat>& image):image_(image)
{
}

bool EditorCommand::operator==(EditorCommand& cmd)
{
	return typeid(cmd) == typeid(*this);
}
