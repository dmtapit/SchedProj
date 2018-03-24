#pragma once
#include <wx/wx.h>

class BasicFrame : public wxFrame
{
public:
	BasicFrame(const wxChar *title, int xpos, int ypos, int width, int height);
	~BasicFrame();

	wxTextCtrl	*theText;
	wxMenuBar *menuBar;
	wxMenu *fileMenu;

	void OnOpenFile(wxCommandEvent & event);
	void OnAbout(wxCommandEvent & event);
	void OnExit(wxCommandEvent & event);
	void OnChooseFont(wxCommandEvent & event);
	void OnChooseDir(wxCommandEvent & event);
	void OnSaveFile(wxCommandEvent & event);
	void OnSaveFileAs(wxCommandEvent & event);

	//void OnNewFrame(wxCommandEvent & event);

	DECLARE_EVENT_TABLE() // Alert the compiler that this class will have an event table
};

enum {
	BASIC_EXIT = wxID_HIGHEST + 1,
	BASIC_OPEN,
	BASIC_SAVE,
	BASIC_SAVE_AS,
	BASIC_FONT,
	BASIC_DIR,
	BASIC_ABOUT
};