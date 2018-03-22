#pragma once
#include <wx/wx.h>

static const wxChar *TITLE = wxT("Title of the App Under Construction");
static const wxChar *FILETYPES = wxT(
	"Text files|*.txt|"
	"C/C++ source files|*.cpp;*.cc;*.c|"
	"C/C++ header files|*.hpp;*.h|"
	"Make files|Mak*;mak*|"
	"Java files|*java|"
	"Hypertext markup files|*html;*htm;*HTML;*HTM|"
	"All files|*.*"
);

class SchedProjApp : public wxApp
{
public:
	virtual bool OnInit(); // Overriding the OnInit() method, thus declare it virtual
};

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

	DECLARE_EVENT_TABLE() // Alert the compiler that this class will have an event table
};

enum {
	BASIC_EXIT = 1,
	BASIC_OPEN = 100,
	BASIC_ABOUT = 200,
	BASIC_FONT = 300
};