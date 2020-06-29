#include "TxtReader.h"
#include <fstream>
#include <iostream>
#include <vector>
#define SIZE 9

TxtReader::TxtReader(){};

int TxtReader::getGridFromTxt(const char* fileName, std::vector<Grid> &g)
{
    g.clear();
    std::ifstream file;
    file.open(fileName);
    int ctr = 0;

    if(!file.is_open()) return 0;

    while(!file.eof())
    {
       Grid gr;
       for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                file >> gr.grid[i][j];
            }
        }
       g.push_back(gr);
       ctr++;
    }
    file.clear();
    file.close();
    return ctr;
}

bool TxtReader::saveGrid(const char* fileName, const Grid &g)
{
    std::fstream file;
    file.open(fileName, std::ios::app);

    if(!file.is_open()) return false;
    file << "\n\n";
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            file << g.grid[i][j] << " ";
        }
        file << "\n";
    }
    return true;
}
