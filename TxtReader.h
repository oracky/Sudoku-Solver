#ifndef TXTREADER_H_INCLUDED
#define TXTREADER_H_INCLUDED
#include <string>
#include <vector>
#include "SudokuMain.h"

//#define SIZE 9

class TxtReader
{
public:
    static int getGridFromTxt(const char* filePath, std::vector<Grid> &g);
    static bool saveGrid(const char* filePath, const Grid &g);
private:
    TxtReader();
};


#endif // TXTREADER_H_INCLUDED
