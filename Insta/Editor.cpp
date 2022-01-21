#include "Editor.h"
#include <algorithm>
#include <set>

void Editor::add_command(std::unique_ptr<EditorCommand> cmd)
{
	if (!history_.empty())
	{

		for (auto& previous_cmd : history_)
		{
			if (*previous_cmd.first == *cmd)
			{
				previous_cmd.second = false;
			}
		}
	}
	history_.emplace_back(std::move(cmd), true); // emplace_back
}

void Editor::undo()
{

}

void Editor::apply_condition()
{
	if (!history_.empty())
	{

		for (auto& cmd : history_)
		{
			if (cmd.second)
			{
				cmd.first->redo();
			}
		}
	}
}
