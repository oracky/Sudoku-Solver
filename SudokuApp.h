/***************************************************************
 * Name:      SudokuApp.h
 * Purpose:   Defines Application Class
 * Author:    Weronika Wojtan ()
 * Created:   2020-05-13
 * Copyright: Weronika Wojtan ()
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
