#ifndef INPUT_COMMAND_H
#define INPUT_COMMAND_H

struct InputCommand
{
	int row;
	int col;
	int value;
	void Execute(int row,int col,int oldValue);
};
#endif // !INPUT_COMMAND_H

