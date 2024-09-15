#include<iostream>
using namespace std;
#include "CommandInvoker.h"
#include "InputCommand.h"

void CommandInvoker::ExecuteCommand(int row,int col, int oldValue)
{
	InputCommand inputCommand;
	inputCommand.Execute(row, col, oldValue);
	RegisterCommand(inputCommand);
}

void CommandInvoker::RegisterCommand(InputCommand command)
{
	commands.push(command);
}

InputCommand CommandInvoker::UndoCommand()
{
	InputCommand undo;
	undo.row = -1, undo.col = -1,undo.value=-1;
	if (commands.size() > 0)
	{
		undo = commands.top();
		commands.pop();
		return undo;
	}

	cout << "\nNo more UNDO steps!\n";
	return undo;
}