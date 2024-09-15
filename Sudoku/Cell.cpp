#include "Cell.h"

Cell::Cell()
{
	cellValue = 0;
	cellState = FIXED;
}

void Cell::SetCellValue(int cellValue)
{
	this->cellValue = cellValue;
}

void Cell::SetCellState(CellState cellState)
{
	this->cellState = cellState;
}

int Cell::GetCellValue() { return cellValue; }

CellState Cell::GetCellState() { return cellState; }