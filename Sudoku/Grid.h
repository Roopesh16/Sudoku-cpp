#include "Cell.h"
#ifndef GRID_H
#define GRID_H

#define N 9
#define MIN_VAL 1
#define MAX_VAL 9

class Grid
{
private:
	Cell* cells[N][N];
	void SetSudoku();
	bool IsSafe(int row, int col,int value);
public:
	Grid();
	void PrintSudoku();
	bool GetInput(int row, int col,int value);
	Cell* GetCell(int row, int col);
};

#endif GRID_H
