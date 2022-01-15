#pragma once
#include "EditorCommand.h"
#include <memory>
class Editor
{
public:
	void addAndExecuteCommand(std::unique_ptr<EditorCommand> cmd);
	void undo();
private:
	std::vector<std::unique_ptr<EditorCommand>> commands_;
};

