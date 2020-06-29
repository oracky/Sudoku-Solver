#include "Sudoku.h"
#include <iostream>
#include <string.h>

using namespace std;

Sudoku::Sudoku(){}


bool Sudoku::solve(int grid[SIZE][SIZE])
{
    int row, col;

    if (!Sudoku::findUnassignedLocation(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve(grid))
                return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

bool Sudoku::findUnassignedLocation(int grid[SIZE][SIZE], int& row, int& col)
{
    for (row = 0; row < SIZE; row++)
        for (col = 0; col < SIZE; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool Sudoku::isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
     return !Sudoku::usedInRow(grid, row, num)
           && !Sudoku::usedInCol(grid, col, num)
           && !Sudoku::usedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == 0;
}

bool Sudoku::usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol]
                == num)
                return true;
    return false;
}

bool Sudoku::usedInCol(int grid[SIZE][SIZE], int col, int num)
{
    for (int row = 0; row < SIZE; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool Sudoku::usedInRow(int grid[SIZE][SIZE], int row, int num)
{
    for (int col = 0; col < SIZE; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}


