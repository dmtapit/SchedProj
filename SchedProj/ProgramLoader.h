#pragma once
#include <wx/wx.h>

class ButtonPanel : public wxPanel
{
public:
	ButtonPanel(wxPanel *parent);

	void OnBasicDialog(wxCommandEvent& event);
	void OnCellDialog(wxCommandEvent& event);

	wxButton *btn_Basic;
	wxButton *btn_CellSheet;
	wxButton *btn_unused_slot02;

};

enum {
	BASIC_APPLICATION = wxID_HIGHEST + 1,
	CELL_SHEET
};

class ProgramLoader : public wxFrame
{
public:
	ProgramLoader(const wxChar *title, int xpos, int ypos, int width, int height);

	wxMenuBar *menuBar;
	wxMenu *fileMenu;

	void OnLoadProgram(wxCommandEvent& event);

	ButtonPanel *btnPanel;

	DECLARE_EVENT_TABLE()
};

enum {
	LOAD_PROGRAM = wxID_HIGHEST + 1
};