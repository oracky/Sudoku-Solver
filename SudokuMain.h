/***************************************************************
 * Name:      SudokuMain.h
 * Purpose:   Defines Application Frame
 * Author:    Beata Rogala ()
 * Created:   2020-05-13
 * Copyright: Beata Rogala ()
 * License:
 **************************************************************/

#ifndef SUDOKUMAIN_H
#define SUDOKUMAIN_H

//(*Headers(SudokuDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class SudokuDialog: public wxDialog
{
    public:

        SudokuDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~SudokuDialog();
    private:
        bool pobierz_liczby(int X[9][9]);
        void wpisz_liczby(int X[9][9]);

    public:

        //(*Handlers(SudokuDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
                void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(SudokuDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL8;
        static const long ID_TEXTCTRL9;
        static const long ID_PANEL1;
        static const long ID_TEXTCTRL10;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL13;
        static const long ID_TEXTCTRL14;
        static const long ID_TEXTCTRL15;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL17;
        static const long ID_TEXTCTRL18;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL19;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL21;
        static const long ID_TEXTCTRL22;
        static const long ID_TEXTCTRL23;
        static const long ID_TEXTCTRL24;
        static const long ID_TEXTCTRL25;
        static const long ID_TEXTCTRL26;
        static const long ID_TEXTCTRL27;
        static const long ID_PANEL3;
        static const long ID_TEXTCTRL28;
        static const long ID_TEXTCTRL29;
        static const long ID_TEXTCTRL30;
        static const long ID_TEXTCTRL31;
        static const long ID_TEXTCTRL32;
        static const long ID_TEXTCTRL33;
        static const long ID_TEXTCTRL34;
        static const long ID_TEXTCTRL35;
        static const long ID_TEXTCTRL36;
        static const long ID_PANEL4;
        static const long ID_TEXTCTRL37;
        static const long ID_TEXTCTRL38;
        static const long ID_TEXTCTRL39;
        static const long ID_TEXTCTRL40;
        static const long ID_TEXTCTRL41;
        static const long ID_TEXTCTRL42;
        static const long ID_TEXTCTRL43;
        static const long ID_TEXTCTRL44;
        static const long ID_TEXTCTRL45;
        static const long ID_PANEL5;
        static const long ID_TEXTCTRL46;
        static const long ID_TEXTCTRL47;
        static const long ID_TEXTCTRL48;
        static const long ID_TEXTCTRL49;
        static const long ID_TEXTCTRL50;
        static const long ID_TEXTCTRL51;
        static const long ID_TEXTCTRL52;
        static const long ID_TEXTCTRL53;
        static const long ID_TEXTCTRL54;
        static const long ID_PANEL6;
        static const long ID_TEXTCTRL55;
        static const long ID_TEXTCTRL56;
        static const long ID_TEXTCTRL57;
        static const long ID_TEXTCTRL58;
        static const long ID_TEXTCTRL59;
        static const long ID_TEXTCTRL60;
        static const long ID_TEXTCTRL61;
        static const long ID_TEXTCTRL62;
        static const long ID_TEXTCTRL63;
        static const long ID_PANEL7;
        static const long ID_TEXTCTRL64;
        static const long ID_TEXTCTRL65;
        static const long ID_TEXTCTRL66;
        static const long ID_TEXTCTRL67;
        static const long ID_TEXTCTRL68;
        static const long ID_TEXTCTRL69;
        static const long ID_TEXTCTRL70;
        static const long ID_TEXTCTRL71;
        static const long ID_TEXTCTRL72;
        static const long ID_PANEL8;
        static const long ID_TEXTCTRL73;
        static const long ID_TEXTCTRL74;
        static const long ID_TEXTCTRL75;
        static const long ID_TEXTCTRL76;
        static const long ID_TEXTCTRL77;
        static const long ID_TEXTCTRL78;
        static const long ID_TEXTCTRL79;
        static const long ID_TEXTCTRL80;
        static const long ID_TEXTCTRL81;
        static const long ID_PANEL9;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(SudokuDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxPanel* Panel4;
        wxPanel* Panel5;
        wxPanel* Panel6;
        wxPanel* Panel7;
        wxPanel* Panel8;
        wxPanel* Panel9;
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl10;
        wxTextCtrl* TextCtrl11;
        wxTextCtrl* TextCtrl12;
        wxTextCtrl* TextCtrl13;
        wxTextCtrl* TextCtrl14;
        wxTextCtrl* TextCtrl15;
        wxTextCtrl* TextCtrl16;
        wxTextCtrl* TextCtrl17;
        wxTextCtrl* TextCtrl18;
        wxTextCtrl* TextCtrl19;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl20;
        wxTextCtrl* TextCtrl21;
        wxTextCtrl* TextCtrl22;
        wxTextCtrl* TextCtrl23;
        wxTextCtrl* TextCtrl24;
        wxTextCtrl* TextCtrl25;
        wxTextCtrl* TextCtrl26;
        wxTextCtrl* TextCtrl27;
        wxTextCtrl* TextCtrl28;
        wxTextCtrl* TextCtrl29;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl30;
        wxTextCtrl* TextCtrl31;
        wxTextCtrl* TextCtrl32;
        wxTextCtrl* TextCtrl33;
        wxTextCtrl* TextCtrl34;
        wxTextCtrl* TextCtrl35;
        wxTextCtrl* TextCtrl36;
        wxTextCtrl* TextCtrl37;
        wxTextCtrl* TextCtrl38;
        wxTextCtrl* TextCtrl39;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl40;
        wxTextCtrl* TextCtrl41;
        wxTextCtrl* TextCtrl42;
        wxTextCtrl* TextCtrl43;
        wxTextCtrl* TextCtrl44;
        wxTextCtrl* TextCtrl45;
        wxTextCtrl* TextCtrl46;
        wxTextCtrl* TextCtrl47;
        wxTextCtrl* TextCtrl48;
        wxTextCtrl* TextCtrl49;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl50;
        wxTextCtrl* TextCtrl51;
        wxTextCtrl* TextCtrl52;
        wxTextCtrl* TextCtrl53;
        wxTextCtrl* TextCtrl54;
        wxTextCtrl* TextCtrl55;
        wxTextCtrl* TextCtrl56;
        wxTextCtrl* TextCtrl57;
        wxTextCtrl* TextCtrl58;
        wxTextCtrl* TextCtrl59;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl60;
        wxTextCtrl* TextCtrl61;
        wxTextCtrl* TextCtrl62;
        wxTextCtrl* TextCtrl63;
        wxTextCtrl* TextCtrl64;
        wxTextCtrl* TextCtrl65;
        wxTextCtrl* TextCtrl66;
        wxTextCtrl* TextCtrl67;
        wxTextCtrl* TextCtrl68;
        wxTextCtrl* TextCtrl69;
        wxTextCtrl* TextCtrl6;
        wxTextCtrl* TextCtrl70;
        wxTextCtrl* TextCtrl71;
        wxTextCtrl* TextCtrl72;
        wxTextCtrl* TextCtrl73;
        wxTextCtrl* TextCtrl74;
        wxTextCtrl* TextCtrl75;
        wxTextCtrl* TextCtrl76;
        wxTextCtrl* TextCtrl77;
        wxTextCtrl* TextCtrl78;
        wxTextCtrl* TextCtrl79;
        wxTextCtrl* TextCtrl7;
        wxTextCtrl* TextCtrl80;
        wxTextCtrl* TextCtrl81;
        wxTextCtrl* TextCtrl8;
        wxTextCtrl* TextCtrl9;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SUDOKUMAIN_H
