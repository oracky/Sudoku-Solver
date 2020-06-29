#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9

class Sudoku
{
public:
    bool findUnassignedLocation(int grid[SIZE][SIZE], int& row, int& col);
    bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
    bool usedInRow(int grid[SIZE][SIZE], int row, int num);
    bool usedInCol(int grid[SIZE][SIZE], int col, int num);
    bool usedInBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num);
    bool solve(int grid[SIZE][SIZE]);
    int getNumberOfSolutions() const;
    Sudoku();
private:
    int numOfSolutions;

};

#endif // SUDOKU_H
