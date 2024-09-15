#include "Utilities.h"

#ifndef CELL_H
#define CELL_H

#define N 9

class Cell
{
private:
	int cellValue;
	CellState cellState;

public:
	Cell();
	void SetCellValue(int cellValue);
	void SetCellState(CellState cellState);
	int GetCellValue();
	CellState GetCellState();
};
#endif CELL_H

