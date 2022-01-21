#pragma once
#include "EditorCommand.h"
#include <memory>
#include <set>

class Editor
{
public:
	void add_command(std::unique_ptr<EditorCommand> cmd);
	void undo();
	void apply_condition();
private:
	std::vector<std::pair<std::unique_ptr<EditorCommand>, bool>> history_;
};

