#pragma once
#include <wx/wx.h>

//  This is the MAIN FRAME code for Sched Project. Can move to a separate file if you want later.  //
//  Based off of minimal.cpp sample code.

class SchedProjFrame : public wxFrame
{
public:
	// ctor(s) (constructors)
	SchedProjFrame(const wxString& title);

	// event handlers (these functions should not be virtual)
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnNewList(wxCommandEvent& event); // This should aim to create a new list

private:
	// any class wishing to process wxWidgets events must use this macro
	wxDECLARE_EVENT_TABLE();
};

// ID's for controls and menu commands
enum
{
	//menu items
	Minimal_Quit = wxID_EXIT,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	Minimal_About = wxID_ABOUT,
	
	//------------------------------------------------------------------------
	ON_NEW_LIST = wxID_HIGHEST + 1
};