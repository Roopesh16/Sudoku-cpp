#include "Grid.h"
#include<cstdlib>
#include <iostream>
using namespace std;

Grid::Grid()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cells[i][j] = new Cell();
		}
	}
	SetSudoku();
}

void Grid::PrintSudoku()
{
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cells[i][j]->GetCellState() == EMPTY)
			{
				cout << " - ";
			}
			else
			{
				cout << " " << cells[i][j]->GetCellValue() << " ";
			}
		}
		cout << "\n";
	}
}

void Grid::SetSudoku()
{
	int sudoku[N][N] =
	{
		{0,8,0,7,0,3,0,9,0},
		{0,0,6,0,1,8,0,4,0},
		{1,5,7,0,0,6,8,0,0},
		{0,7,0,5,0,1,0,0,4},
		{8,3,1,0,4,0,2,0,0},
		{5,0,0,8,0,0,0,1,0},
		{0,0,5,9,6,2,0,7,8},
		{0,0,0,0,0,0,4,2,9},
		{9,2,8,0,7,0,0,0,0}
	};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cells[i][j]->SetCellValue(sudoku[i][j]);

			if (sudoku[i][j] == 0)
			{
				cells[i][j]->SetCellState(EMPTY);
			}
			else
			{
				cells[i][j]->SetCellState(FIXED);
			}
		}
	}
}

bool Grid::IsSafe(int row, int col,int value)
{
	// Check in column
	for (int i = 0; i < N; i++)
	{
		if (cells[row][i]->GetCellValue() == value)
			return false;
	}

	// Check in row
	for (int i = 0; i < N; i++)
	{
		if (cells[i][col]->GetCellValue() == value)
			return false;
	}

	// Check in 3*3 box
	int newRow = row - row % 3, newCol = col - col % 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cells[i + newRow][j + newCol]->GetCellValue() == value)
				return false;
		}
	}

	return true;
}

bool Grid::GetInput(int row, int col,int value)
{
	if (cells[row][col]->GetCellState() == FIXED)
	{
		cout << "\nThis cell cannot be changed\n";
		return false;
	}

	if (IsSafe(row, col, value))
	{
		cells[row][col]->SetCellState(CHANGEABLE);
		return true;
	}
		
	cout << "\nWRONG INPUT\n";
	return false;
}

Cell* Grid::GetCell(int row, int col)
{
	return cells[row][col];
}