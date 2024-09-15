#include "Grid.h"
#include "GameManager.h"
#include "CommandInvoker.h"
#include "InputCommand.h"
#include <iostream>
using namespace std;

std::ostream& bold_on(std::ostream& os) { return os << "\e[1m"; }

std::ostream& bold_off(std::ostream& os) { return os << "\e[0m"; }

Grid* grid;
CommandInvoker* invoker;

void InfoDisplay()
{
    cout <<bold_on <<"SUDOKU\n"<<bold_off;
    cout << "Sudoku is played on a grid of 9 x 9 spaces.\n";
    cout << "Each of the digits 1 - 9 must occur exactly once in each row.\n";
    cout << "Each of the digits 1 - 9 must occur exactly once in each column.\n";
    cout << "Each of the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.\n";

    cout << "\n RULES : \n";
    cout << "\n1. Enter '1' to enter value\n";
    cout << "2. Enter '2' to Undo last step. (You only have 5 undos in a match)\n";
    cout << "3. Enter '-1' to Exit the Game!\n";
    cout << "\n";
}

void Input()
{
    int row, col, value;

    cout << "\nEnter row : ";
    cin >> row;
    cout << "\nEnter col : ";
    cin >> col;
    cout << "\nEnter value : ";
    cin >> value;

    if (grid->GetInput(row, col, value))
    {
        invoker->ExecuteCommand(row, col, grid->GetCell(row, col)->GetCellValue());
        grid->GetCell(row, col)->SetCellValue(value);
    }
    
    grid->PrintSudoku();
}

void Undo()
{
    InputCommand undo = invoker->UndoCommand();

    if (undo.row == -1 || undo.col == -1 || undo.value == -1)
        return;

    grid->GetCell(undo.row, undo.col)->SetCellValue(undo.value);

    if (grid->GetCell(undo.row, undo.col)->GetCellValue() == 0)
        grid->GetCell(undo.row, undo.col)->SetCellState(EMPTY);

    cout << "\n UNDO!\n";
    grid->PrintSudoku();
}


int main()
{
    InfoDisplay();
    grid = new Grid();
    invoker = new CommandInvoker();
    grid->PrintSudoku();
    GameManager* manager = new GameManager();
    manager->SetGameState(PLAY);

    while (manager->GetGameState() == PLAY)
    {
        int input;
        cout << "\nEnter command : ";
        cin >> input;

        switch (input)
        {
        case 1: Input();
            break;

        case 2: Undo();
            break;

        case -1: manager->SetGameState(OVER);
            break;
        }
    }
}
