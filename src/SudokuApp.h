/***************************************************************
 * Name:      SudokuApp.h
 * Purpose:   Defines Application Class
 * Author:    Michal Oracki
 * Created:   2020-06-12
 * Copyright:
 * License:
 **************************************************************/

#ifndef SUDOKUAPP_H
#define SUDOKUAPP_H

#include <wx/app.h>

class SudokuApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SUDOKUAPP_H
