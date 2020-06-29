/***************************************************************
 * Name:      SudokuApp.cpp
 * Purpose:   Code for Application Class
 * Author:    D (D)
 * Created:   2020-06-12
 * Copyright: D (D)
 * License:
 **************************************************************/

#include "SudokuApp.h"

//(*AppHeaders
#include "SudokuMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SudokuApp);

bool SudokuApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SudokuDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
