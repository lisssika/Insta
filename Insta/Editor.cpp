#include "Editor.h"
#include <algorithm>
#include <set>

void Editor::add_command(std::unique_ptr<EditorCommand> cmd)
{
	if (!history_.empty())
	{
		for (size_t i = history_.size(); i > 0; i-- )
		{
			if (*history_[i-1].first == *cmd)
			{
				history_[i-1].second = false;
				break;
			}
		}
	}
	history_.emplace_back(std::move(cmd), true); // emplace_back
}

void Editor::undo()
{
	auto cmd = std::move(history_.back().first); // danger
	history_.pop_back();

	if (!history_.empty())
	{
		for (size_t i = history_.size() - 1; i >= 0; i--)
		{
			if (*history_[i].first == *cmd)
			{
				history_[i].first->redo();
				history_[i].second = true;
				return;
			}
		}
	}
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
