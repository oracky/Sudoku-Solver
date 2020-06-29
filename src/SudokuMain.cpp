/***************************************************************
 * Name:      SudokuMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Michal Oracki
 * Created:   2020-06-12
 * Copyright:
 * License:
 **************************************************************/

#include "SudokuMain.h"
#include <wx/msgdlg.h>
#include <vector>
#include "Sudoku.h"
#include "TxtReader.h"
#include <string>
#include <iostream>
#include <unordered_map>

#define FIELD_VALUES w(1)w(2)w(3)w(4)w(5)w(6)w(7)w(8)w(9)w(10)w(11)w(12)w(13)w(14)w(15)w(16)w(17)w(18)w(19)w(20)w(21)w(22)w(23)w(24)w(25)w(26)w(27)w(28)w(29)w(30)w(31)w(32)w(33)w(34)w(35)w(36)w(37)w(38)w(39)w(40)w(41)w(42)w(43)w(44)w(45)w(46)w(47)w(48)w(49)w(50)w(51)w(52)w(53)w(54)w(55)w(56)w(57)w(58)w(59)w(60)w(61)w(62)w(63)w(64)w(65)w(66)w(67)w(68)w(69)w(70)w(71)w(72)w(73)w(74)w(75)w(76)w(77)w(78)w(79)w(80)w(81)

//using namespace std;

//(*InternalHeaders(SudokuDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

// Auto generated code
//(*IdInit(SudokuDialog)
const long SudokuDialog::ID_STATICTEXT1 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL1 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL2 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL3 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL4 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL5 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL6 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL7 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL8 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL9 = wxNewId();
const long SudokuDialog::ID_PANEL1 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL10 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL11 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL12 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL13 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL14 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL15 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL16 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL17 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL18 = wxNewId();
const long SudokuDialog::ID_PANEL2 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL19 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL20 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL21 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL22 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL23 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL24 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL25 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL26 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL27 = wxNewId();
const long SudokuDialog::ID_PANEL3 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL28 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL29 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL30 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL31 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL32 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL33 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL34 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL35 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL36 = wxNewId();
const long SudokuDialog::ID_PANEL4 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL37 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL38 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL39 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL40 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL41 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL42 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL43 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL44 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL45 = wxNewId();
const long SudokuDialog::ID_PANEL5 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL46 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL47 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL48 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL49 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL50 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL51 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL52 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL53 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL54 = wxNewId();
const long SudokuDialog::ID_PANEL6 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL55 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL56 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL57 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL58 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL59 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL60 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL61 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL62 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL63 = wxNewId();
const long SudokuDialog::ID_PANEL7 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL64 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL65 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL66 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL67 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL68 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL69 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL70 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL71 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL72 = wxNewId();
const long SudokuDialog::ID_PANEL8 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL73 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL74 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL75 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL76 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL77 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL78 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL79 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL80 = wxNewId();
const long SudokuDialog::ID_TEXTCTRL81 = wxNewId();
const long SudokuDialog::ID_PANEL9 = wxNewId();
const long SudokuDialog::ID_BUTTON1 = wxNewId();
const long SudokuDialog::ID_BUTTON2 = wxNewId();
const long SudokuDialog::ID_BUTTON3 = wxNewId();
const long SudokuDialog::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SudokuDialog,wxDialog)
    //(*EventTable(SudokuDialog)
    //*)
END_EVENT_TABLE()

SudokuDialog::SudokuDialog(wxWindow* parent,wxWindowID id)
{
    // Auto generated code
    //(*Initialize(SudokuDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxGridSizer* GridSizer10;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer3;
    wxGridSizer* GridSizer4;
    wxGridSizer* GridSizer5;
    wxGridSizer* GridSizer6;
    wxGridSizer* GridSizer7;
    wxGridSizer* GridSizer8;
    wxGridSizer* GridSizer9;

    Create(parent, wxID_ANY, _("SUDOKU"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(8, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("SUDOKU"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(198,198,255));
    GridSizer2 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    GridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    wxFont TextCtrl2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl2->SetFont(TextCtrl2Font);
    GridSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    wxFont TextCtrl3Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl3->SetFont(TextCtrl3Font);
    GridSizer2->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    wxFont TextCtrl4Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl4->SetFont(TextCtrl4Font);
    GridSizer2->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    wxFont TextCtrl5Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl5->SetFont(TextCtrl5Font);
    GridSizer2->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    wxFont TextCtrl6Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl6->SetFont(TextCtrl6Font);
    GridSizer2->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl7 = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    wxFont TextCtrl7Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl7->SetFont(TextCtrl7Font);
    GridSizer2->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl8 = new wxTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    wxFont TextCtrl8Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl8->SetFont(TextCtrl8Font);
    GridSizer2->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl9 = new wxTextCtrl(Panel1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel1,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    wxFont TextCtrl9Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl9->SetFont(TextCtrl9Font);
    GridSizer2->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(GridSizer2);
    GridSizer2->Fit(Panel1);
    GridSizer2->SetSizeHints(Panel1);
    GridSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxColour(147,147,255));
    GridSizer3 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl10 = new wxTextCtrl(Panel2, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    wxFont TextCtrl10Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl10->SetFont(TextCtrl10Font);
    GridSizer3->Add(TextCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl11 = new wxTextCtrl(Panel2, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    wxFont TextCtrl11Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl11->SetFont(TextCtrl11Font);
    GridSizer3->Add(TextCtrl11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl12 = new wxTextCtrl(Panel2, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    wxFont TextCtrl12Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl12->SetFont(TextCtrl12Font);
    GridSizer3->Add(TextCtrl12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl13 = new wxTextCtrl(Panel2, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    wxFont TextCtrl13Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl13->SetFont(TextCtrl13Font);
    GridSizer3->Add(TextCtrl13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl14 = new wxTextCtrl(Panel2, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    wxFont TextCtrl14Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl14->SetFont(TextCtrl14Font);
    GridSizer3->Add(TextCtrl14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl15 = new wxTextCtrl(Panel2, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    wxFont TextCtrl15Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl15->SetFont(TextCtrl15Font);
    GridSizer3->Add(TextCtrl15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl16 = new wxTextCtrl(Panel2, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    wxFont TextCtrl16Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl16->SetFont(TextCtrl16Font);
    GridSizer3->Add(TextCtrl16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl17 = new wxTextCtrl(Panel2, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    wxFont TextCtrl17Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl17->SetFont(TextCtrl17Font);
    GridSizer3->Add(TextCtrl17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl18 = new wxTextCtrl(Panel2, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel2,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    wxFont TextCtrl18Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl18->SetFont(TextCtrl18Font);
    GridSizer3->Add(TextCtrl18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(GridSizer3);
    GridSizer3->Fit(Panel2);
    GridSizer3->SetSizeHints(Panel2);
    GridSizer1->Add(Panel2, 1, wxALL|wxEXPAND, 5);
    Panel3 = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->SetBackgroundColour(wxColour(198,198,255));
    GridSizer4 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl19 = new wxTextCtrl(Panel3, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    wxFont TextCtrl19Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    TextCtrl19->SetFont(TextCtrl19Font);
    GridSizer4->Add(TextCtrl19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl20 = new wxTextCtrl(Panel3, ID_TEXTCTRL20, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    GridSizer4->Add(TextCtrl20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl21 = new wxTextCtrl(Panel3, ID_TEXTCTRL21, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    GridSizer4->Add(TextCtrl21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl22 = new wxTextCtrl(Panel3, ID_TEXTCTRL22, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    GridSizer4->Add(TextCtrl22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl23 = new wxTextCtrl(Panel3, ID_TEXTCTRL23, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    GridSizer4->Add(TextCtrl23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl24 = new wxTextCtrl(Panel3, ID_TEXTCTRL24, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    GridSizer4->Add(TextCtrl24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl25 = new wxTextCtrl(Panel3, ID_TEXTCTRL25, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL25"));
    GridSizer4->Add(TextCtrl25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl26 = new wxTextCtrl(Panel3, ID_TEXTCTRL26, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL26"));
    GridSizer4->Add(TextCtrl26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl27 = new wxTextCtrl(Panel3, ID_TEXTCTRL27, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel3,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL27"));
    GridSizer4->Add(TextCtrl27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(GridSizer4);
    GridSizer4->Fit(Panel3);
    GridSizer4->SetSizeHints(Panel3);
    GridSizer1->Add(Panel3, 1, wxALL|wxEXPAND, 5);
    Panel4 = new wxPanel(this, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel4->SetBackgroundColour(wxColour(147,147,255));
    GridSizer5 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl28 = new wxTextCtrl(Panel4, ID_TEXTCTRL28, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL28"));
    GridSizer5->Add(TextCtrl28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl29 = new wxTextCtrl(Panel4, ID_TEXTCTRL29, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL29"));
    GridSizer5->Add(TextCtrl29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl30 = new wxTextCtrl(Panel4, ID_TEXTCTRL30, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL30"));
    GridSizer5->Add(TextCtrl30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl31 = new wxTextCtrl(Panel4, ID_TEXTCTRL31, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL31"));
    GridSizer5->Add(TextCtrl31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl32 = new wxTextCtrl(Panel4, ID_TEXTCTRL32, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL32"));
    GridSizer5->Add(TextCtrl32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl33 = new wxTextCtrl(Panel4, ID_TEXTCTRL33, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL33"));
    GridSizer5->Add(TextCtrl33, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl34 = new wxTextCtrl(Panel4, ID_TEXTCTRL34, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL34"));
    GridSizer5->Add(TextCtrl34, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl35 = new wxTextCtrl(Panel4, ID_TEXTCTRL35, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL35"));
    GridSizer5->Add(TextCtrl35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl36 = new wxTextCtrl(Panel4, ID_TEXTCTRL36, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel4,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL36"));
    GridSizer5->Add(TextCtrl36, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(GridSizer5);
    GridSizer5->Fit(Panel4);
    GridSizer5->SetSizeHints(Panel4);
    GridSizer1->Add(Panel4, 1, wxALL|wxEXPAND, 5);
    Panel5 = new wxPanel(this, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel5->SetBackgroundColour(wxColour(198,198,255));
    GridSizer6 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl37 = new wxTextCtrl(Panel5, ID_TEXTCTRL37, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL37"));
    GridSizer6->Add(TextCtrl37, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl38 = new wxTextCtrl(Panel5, ID_TEXTCTRL38, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL38"));
    GridSizer6->Add(TextCtrl38, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl39 = new wxTextCtrl(Panel5, ID_TEXTCTRL39, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL39"));
    GridSizer6->Add(TextCtrl39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl40 = new wxTextCtrl(Panel5, ID_TEXTCTRL40, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL40"));
    GridSizer6->Add(TextCtrl40, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl41 = new wxTextCtrl(Panel5, ID_TEXTCTRL41, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL41"));
    GridSizer6->Add(TextCtrl41, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl42 = new wxTextCtrl(Panel5, ID_TEXTCTRL42, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL42"));
    GridSizer6->Add(TextCtrl42, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl43 = new wxTextCtrl(Panel5, ID_TEXTCTRL43, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL43"));
    GridSizer6->Add(TextCtrl43, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl44 = new wxTextCtrl(Panel5, ID_TEXTCTRL44, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL44"));
    GridSizer6->Add(TextCtrl44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl45 = new wxTextCtrl(Panel5, ID_TEXTCTRL45, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel5,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL45"));
    GridSizer6->Add(TextCtrl45, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel5->SetSizer(GridSizer6);
    GridSizer6->Fit(Panel5);
    GridSizer6->SetSizeHints(Panel5);
    GridSizer1->Add(Panel5, 1, wxALL|wxEXPAND, 5);
    Panel6 = new wxPanel(this, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Panel6->SetBackgroundColour(wxColour(147,147,255));
    GridSizer7 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl46 = new wxTextCtrl(Panel6, ID_TEXTCTRL46, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL46"));
    GridSizer7->Add(TextCtrl46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl47 = new wxTextCtrl(Panel6, ID_TEXTCTRL47, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL47"));
    GridSizer7->Add(TextCtrl47, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl48 = new wxTextCtrl(Panel6, ID_TEXTCTRL48, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL48"));
    GridSizer7->Add(TextCtrl48, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl49 = new wxTextCtrl(Panel6, ID_TEXTCTRL49, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL49"));
    GridSizer7->Add(TextCtrl49, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl50 = new wxTextCtrl(Panel6, ID_TEXTCTRL50, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL50"));
    GridSizer7->Add(TextCtrl50, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl51 = new wxTextCtrl(Panel6, ID_TEXTCTRL51, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL51"));
    GridSizer7->Add(TextCtrl51, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl52 = new wxTextCtrl(Panel6, ID_TEXTCTRL52, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL52"));
    GridSizer7->Add(TextCtrl52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl53 = new wxTextCtrl(Panel6, ID_TEXTCTRL53, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL53"));
    GridSizer7->Add(TextCtrl53, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl54 = new wxTextCtrl(Panel6, ID_TEXTCTRL54, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel6,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL54"));
    GridSizer7->Add(TextCtrl54, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(GridSizer7);
    GridSizer7->Fit(Panel6);
    GridSizer7->SetSizeHints(Panel6);
    GridSizer1->Add(Panel6, 1, wxALL|wxEXPAND, 5);
    Panel7 = new wxPanel(this, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    Panel7->SetBackgroundColour(wxColour(198,198,255));
    GridSizer8 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl55 = new wxTextCtrl(Panel7, ID_TEXTCTRL55, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL55"));
    GridSizer8->Add(TextCtrl55, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl56 = new wxTextCtrl(Panel7, ID_TEXTCTRL56, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL56"));
    GridSizer8->Add(TextCtrl56, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl57 = new wxTextCtrl(Panel7, ID_TEXTCTRL57, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL57"));
    GridSizer8->Add(TextCtrl57, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl58 = new wxTextCtrl(Panel7, ID_TEXTCTRL58, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL58"));
    GridSizer8->Add(TextCtrl58, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl59 = new wxTextCtrl(Panel7, ID_TEXTCTRL59, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL59"));
    GridSizer8->Add(TextCtrl59, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl60 = new wxTextCtrl(Panel7, ID_TEXTCTRL60, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL60"));
    GridSizer8->Add(TextCtrl60, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl61 = new wxTextCtrl(Panel7, ID_TEXTCTRL61, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL61"));
    GridSizer8->Add(TextCtrl61, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl62 = new wxTextCtrl(Panel7, ID_TEXTCTRL62, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL62"));
    GridSizer8->Add(TextCtrl62, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl63 = new wxTextCtrl(Panel7, ID_TEXTCTRL63, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel7,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL63"));
    GridSizer8->Add(TextCtrl63, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel7->SetSizer(GridSizer8);
    GridSizer8->Fit(Panel7);
    GridSizer8->SetSizeHints(Panel7);
    GridSizer1->Add(Panel7, 1, wxALL|wxEXPAND, 5);
    Panel8 = new wxPanel(this, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    Panel8->SetBackgroundColour(wxColour(147,147,255));
    GridSizer9 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl64 = new wxTextCtrl(Panel8, ID_TEXTCTRL64, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL64"));
    GridSizer9->Add(TextCtrl64, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl65 = new wxTextCtrl(Panel8, ID_TEXTCTRL65, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL65"));
    GridSizer9->Add(TextCtrl65, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl66 = new wxTextCtrl(Panel8, ID_TEXTCTRL66, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL66"));
    GridSizer9->Add(TextCtrl66, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl67 = new wxTextCtrl(Panel8, ID_TEXTCTRL67, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL67"));
    GridSizer9->Add(TextCtrl67, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl68 = new wxTextCtrl(Panel8, ID_TEXTCTRL68, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL68"));
    GridSizer9->Add(TextCtrl68, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl69 = new wxTextCtrl(Panel8, ID_TEXTCTRL69, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL69"));
    GridSizer9->Add(TextCtrl69, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl70 = new wxTextCtrl(Panel8, ID_TEXTCTRL70, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL70"));
    GridSizer9->Add(TextCtrl70, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl71 = new wxTextCtrl(Panel8, ID_TEXTCTRL71, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL71"));
    GridSizer9->Add(TextCtrl71, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl72 = new wxTextCtrl(Panel8, ID_TEXTCTRL72, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel8,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL72"));
    GridSizer9->Add(TextCtrl72, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel8->SetSizer(GridSizer9);
    GridSizer9->Fit(Panel8);
    GridSizer9->SetSizeHints(Panel8);
    GridSizer1->Add(Panel8, 1, wxALL|wxEXPAND, 5);
    Panel9 = new wxPanel(this, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    Panel9->SetBackgroundColour(wxColour(198,198,255));
    GridSizer10 = new wxGridSizer(3, 3, 0, 0);
    TextCtrl73 = new wxTextCtrl(Panel9, ID_TEXTCTRL73, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL73"));
    GridSizer10->Add(TextCtrl73, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl74 = new wxTextCtrl(Panel9, ID_TEXTCTRL74, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL74"));
    GridSizer10->Add(TextCtrl74, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl75 = new wxTextCtrl(Panel9, ID_TEXTCTRL75, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL75"));
    GridSizer10->Add(TextCtrl75, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl76 = new wxTextCtrl(Panel9, ID_TEXTCTRL76, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL76"));
    GridSizer10->Add(TextCtrl76, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl77 = new wxTextCtrl(Panel9, ID_TEXTCTRL77, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL77"));
    GridSizer10->Add(TextCtrl77, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl78 = new wxTextCtrl(Panel9, ID_TEXTCTRL78, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL78"));
    GridSizer10->Add(TextCtrl78, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl79 = new wxTextCtrl(Panel9, ID_TEXTCTRL79, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL79"));
    GridSizer10->Add(TextCtrl79, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl80 = new wxTextCtrl(Panel9, ID_TEXTCTRL80, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL80"));
    GridSizer10->Add(TextCtrl80, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl81 = new wxTextCtrl(Panel9, ID_TEXTCTRL81, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(Panel9,wxSize(30,30)), 0, wxDefaultValidator, _T("ID_TEXTCTRL81"));
    GridSizer10->Add(TextCtrl81, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel9->SetSizer(GridSizer10);
    GridSizer10->Fit(Panel9);
    GridSizer10->SetSizeHints(Panel9);
    GridSizer1->Add(Panel9, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(1, 4, 0, 0);
    btnResult = new wxButton(this, ID_BUTTON1, _("Result"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(btnResult, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnClear = new wxButton(this, ID_BUTTON2, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer2->Add(btnClear, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnLoad = new wxButton(this, ID_BUTTON3, _("Load Grid"), wxDefaultPosition, wxSize(90,22), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer2->Add(btnLoad, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSave = new wxButton(this, ID_BUTTON4, _("Save Grid"), wxDefaultPosition, wxSize(98,22), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer2->Add(btnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SudokuDialog::OnbtnResultClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SudokuDialog::OnbtnClearClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SudokuDialog::OnbtnLoad);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SudokuDialog::OnbtnSave);
    //*)
    gridNumber = TxtReader::getGridFromTxt("plansze.txt", gridList);
    initializeFonts();
}

SudokuDialog::~SudokuDialog()
{
    //(*Destroy(SudokuDialog)
    //*)
}

bool SudokuDialog::checkRowsAndCols(int X[9][9])
{
    for (int i=0; i<SIZE; i++)
    {
        std::vector<int> rowVals;
        std::vector<int> colVals;
        for (int j=0; j<SIZE; j++)
        {
            int x = X[i][j];
            int y = X[j][i];
            if(find(rowVals.begin(), rowVals.end(), x) != rowVals.end() && x != 0) return false;
            else rowVals.push_back(x);
            if(find(colVals.begin(), colVals.end(), y) != colVals.end() && y != 0) return false;
            else colVals.push_back(y);

        }
    }
    return true;
}

bool SudokuDialog::checkBoxes(int X[9][9])
{
    for (int i=0; i<SIZE; i+=3)
    {
        for(int j=0; j<SIZE; j+=3)
        {
            std::vector<int> boxVals;
            for (int k=0; k<3; k++)
            {
                for (int z=0; z<3; z++)
                {
                    int l = X[k+i][z+j];
                    if(find(boxVals.begin(), boxVals.end(), l) != boxVals.end() && l != 0) return false;
                    else boxVals.push_back(l);
                }
            }
        }

    }
    return true;
}

bool SudokuDialog::transformTo2DArray(const std::vector<wxString> &T, int X[9][9]){
    std::vector<int> U(T.size());
    for (size_t i=0; i< T.size(); i++)
    {
        if (T[i]=="")
            U[i] = 0;
        else
        {
            long tmp;
            if (!T[i].ToLong(&tmp))
                return false;
            else
            {
                int t = static_cast<int>(tmp);
                if ((t<10) && (t>0))
                    U[i] = t;
                else
                    return false;
            }
        }
    }

    for (size_t i=0; i<U.size();i++) {
            int k = i / 9; // k - number of box
            int j = i % 9; // j - position in the box
            int row = (k/3)*3 + j/3;
            int column = (k%3)*3 + j%3;
            X[row][column] = U[i];
    }

    if(!checkRowsAndCols(X)) return false;
    if(!checkBoxes(X)) return false;

    return true;
}

bool SudokuDialog::getNumbers(int X[SIZE][SIZE])
{
   std::vector<wxString> T(81);
   #define w(i) T[i-1] = TextCtrl##i->GetValue();
   FIELD_VALUES
   #undef w
   return transformTo2DArray(T, X);
}

void SudokuDialog::setNumbers(int X[SIZE][SIZE])
{
   std::unordered_map<int, std::string> T;
   for (int row=0; row<9; row++)
        for (int column=0; column<9; column++) {
            int j = (row%3)*3 + column%3;
            int k = (row/3)*3 + column/3;
            int nr = k*9 + j;
            if (X[row][column]==0)
                T.insert(std::make_pair(nr,""));
            else
                T.insert(std::make_pair(nr,std::to_string(X[row][column])));
        }

   #define w(i) TextCtrl##i->SetValue(T[i-1]);
   FIELD_VALUES // set values to all cells
   #undef w
}

void SudokuDialog::clearInputs()
{
    #define w(i) TextCtrl##i->SetValue(_(""));
    FIELD_VALUES
    #undef w
}

void SudokuDialog::initializeFonts()
{
    #define w(i) TextCtrl##i->SetFont(wxFont(26, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
    FIELD_VALUES // set font for all cells
    #undef w
}

void SudokuDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SudokuDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void SudokuDialog::OnbtnResultClick(wxCommandEvent& event)
{
    Grid g;

    if (!getNumbers(g.grid)) {
            std::cout <<"ERROR";
       wxMessageBox( _("Wrong arguments"), "ERROR", wxICON_INFORMATION);
       clearInputs();
    }
    else {

        Sudoku *sudoku = new Sudoku();
        if(!sudoku->solve(g.grid))
        {
            wxMessageBox( _("Current sudoku is impossible to be solved"), "INFO", wxICON_INFORMATION);
            g.possible = false;
        }
        setNumbers(g.grid);

        if(sudoku->getNumberOfSolutions() > 1)
            wxMessageBox(_("Current sudoku has more than one correct result!"), "INFO", wxICON_INFORMATION);
        delete sudoku;
    }
}

void SudokuDialog::OnbtnClearClick(wxCommandEvent& event)
{
    clearInputs();
}

void SudokuDialog::OnbtnLoad(wxCommandEvent& event)
{
    if(gridNumber>0)
    {
        if(gridIndex==gridNumber-1) gridIndex = 0;
        setNumbers(gridList[gridIndex].grid);
        gridIndex++;
    }

}

void SudokuDialog::OnbtnSave(wxCommandEvent& event)
{
    Grid g;

    if (!getNumbers(g.grid)) {
            std::cout <<"ERROR";
       wxMessageBox( _("Wrong arguments"), "ERROR", wxICON_INFORMATION);
       clearInputs();
    }
    else{
        if(!TxtReader::saveGrid("plansze.txt",g))
            wxMessageBox( _("Saving process failed"), "ERROR", wxICON_INFORMATION);
    }

    // update grid list
    gridNumber = TxtReader::getGridFromTxt("plansze.txt", gridList);
    gridIndex = 0;
}
