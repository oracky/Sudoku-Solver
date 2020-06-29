#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9

class Sudoku
{
public:
    static bool findUnassignedLocation(int grid[SIZE][SIZE], int& row, int& col);
    static bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
    static bool usedInRow(int grid[SIZE][SIZE], int row, int num);
    static bool usedInCol(int grid[SIZE][SIZE], int col, int num);
    static bool usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num);
    static bool solve(int grid[SIZE][SIZE]);
private:
    Sudoku();

};

#endif // SUDOKU_H
