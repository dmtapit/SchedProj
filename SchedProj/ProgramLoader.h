#pragma once
#include <wx/wx.h>

class ButtonPanel : public wxPanel
{
public:
	ButtonPanel(wxPanel *parent);

	void OnBasicDialog(wxCommandEvent& event);
	void OnCellDialog(wxCommandEvent& event);
	void OnPanelDrawDialog(wxCommandEvent& event);
	void OnSchedProjDialog(wxCommandEvent& event);

	wxButton *btn_Basic;
	wxButton *btn_CellSheet;
	wxButton *btn_PanelDraw;
	wxButton *btn_SchedProj;

};

enum {
	BASIC_APPLICATION = wxID_HIGHEST + 1,
	CELL_SHEET,
	PANEL_DRAW,
	SCHED_PROJ
};

class ProgramLoader : public wxFrame
{
public:
	ProgramLoader(const wxChar *title, int xpos, int ypos, int width, int height);

	wxMenuBar *menuBar;
	wxMenu *fileMenu;

	void OnQuit(wxCommandEvent& event);

	ButtonPanel *btnPanel;

	DECLARE_EVENT_TABLE()
};

enum {
	QUIT_PROGRAM = wxID_HIGHEST + 1
};