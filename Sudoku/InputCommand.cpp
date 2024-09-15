#include <iostream>
#include "InputCommand.h"
using namespace std;

void InputCommand::Execute(int row,int col,int value)
{
	this->row = row;
	this->col = col;
	this->value = value;
}