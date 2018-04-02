///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		SchedProjFrame.h
// Author:		Dean Tapit
// Last Edit:	4/1/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			This is the MAIN FRAME code for Sched Project.
//			Based off of "minimal.cpp" sample code.
//			Some more code based from "widgets.h"
///////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>

#if wxUSE_TREEBOOK
#include "wx/treebook.h"
#define USE_TREEBOOK 1
#define SchedProjBookCtrl wxTreebook
#endif // wxUSE_TREEBOOK

//////////////////////////////////////////////////////////////////
// ID's for controls and menu commands
//////////////////////////////////////////////////////////////////
enum
{
	// control ids /////////////////////////////////////////////////////////////

	SchedProj_Quit, // For the quit button in SchedProjFrame.cpp, lower panel
	SchedProj_BookCtrl,

	// menu items //////////////////////////////////////////////////////////////
	Minimal_Quit = wxID_EXIT,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	Minimal_About = wxID_ABOUT,

	//------------------------------------------------------------------------
	ON_NEW_LIST = wxID_HIGHEST + 1
};

///////////////////////////////////////////////////////////////////////
//
// MAIN FRAME (Header file code)
//
///////////////////////////////////////////////////////////////////////

class SchedProjFrame : public wxFrame
{
public:
	// ctor(s) (constructors)
	SchedProjFrame(const wxString& title);

	// dtor(s) (destructors)
	virtual ~SchedProjFrame();

	// event handlers (these functions should not be virtual)

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnNewList(wxCommandEvent& event); // This should aim to create a new list

	// initializing the book: add all pages to it
	// [Dean Tapit: since this program really only wants to create a notebook, and not pages of widgets, this may change]
	void InitBook();

private:
	// the panel containing everything
	wxPanel *m_panel;

	// the book containing the test pages (the widgets); in SchedProj, just a notebook...?
	SchedProjBookCtrl *m_book;

	// any class wishing to process wxWidgets events must use this macro
	wxDECLARE_EVENT_TABLE();
};