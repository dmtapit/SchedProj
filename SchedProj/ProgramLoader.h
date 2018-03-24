#pragma once
#include <wx/wx.h>

class ProgramLoader : public wxFrame
{
public:
	ProgramLoader(const wxChar *title, int xpos, int ypos, int width, int height);

	wxMenuBar *menuBar;
	wxMenu *fileMenu;

	void OnLoadProgram(wxCommandEvent & event);

	DECLARE_EVENT_TABLE()
};

enum {
	LOAD_PROGRAM = wxID_HIGHEST + 1
};