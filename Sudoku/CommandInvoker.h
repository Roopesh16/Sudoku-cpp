#include "InputCommand.h"
#include <stack>
using namespace std;

#ifndef COMMAND_INVOKER_H
#define COMMAND_INVOKER_H

class CommandInvoker
{
private:
	stack<InputCommand> commands;
	void RegisterCommand(InputCommand);
public:
	void ExecuteCommand(int row,int col,int oldValue);
	InputCommand UndoCommand();
};
#endif // !COMMAND_INVOKER_H
