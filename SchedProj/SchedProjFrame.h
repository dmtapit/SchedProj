///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		SchedProjFrame.h
// Author:		Dean Tapit
// Last Edit:	4/4/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			This is the MAIN FRAME code for Sched Project.
//			Based off of "minimal.cpp" sample code.
//			Some more code based from "widgets.h" and "widgets.cpp"
///////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>

#if wxUSE_TREEBOOK
#include "wx/treebook.h"
#define USE_TREEBOOK 1
#define SchedProjBookCtrl wxTreebook
#endif // wxUSE_TREEBOOK

#define ICON_SIZE	16

// INTRODUCING NEW PAGES DON'T FORGET TO ADD ENTRIES TOO 'WidgetCategories'
// [Dean Tapit] I'm assuming that this means these enums are the labels for the pages
// of the Treebook, where all the widgets can be chosen just as in sample "widgets.cpp"
// My aim at the moment is to just open one widget: the notebook.cpp
enum
{
	// [Dean Tapit] I still don't have a good grasp of most of the code in the "widgets.cpp"
	// sample app.  It is quite interesting, though...
	MAX_PAGES = 1
};

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

typedef wxVector<wxWindow *> Widgets;

//////////////////////////////////////////////////////////////////////////////////////////
// SchedProjPage: a book page demonstrating some widget (notebook.cpp to start...)
//////////////////////////////////////////////////////////////////////////////////////////

// struct to store common widget attributes
struct SchedProjAttributes
{
	SchedProjAttributes()
	{
		m_enabled = true;
	}

	bool m_enabled;
};

class SchedProjPage : public wxPanel
{
public:
	SchedProjPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[]);
	
	// return the control shown by this page
	virtual wxWindow *GetWidget() const = 0;

	// some pages show additional controls, in this case override this one to
	// return all of them (including the one returned by GetWidget())
	virtual Widgets GetWidgets() const
	{
		Widgets widgets;
		widgets.push_back(GetWidget());
		return widgets;
	}

	// apply current attributes to the widget(s)
	void SetUpWidget();

	// the default attributes for the widget
	static SchedProjAttributes& GetAttrs();

protected:

};




///////////////////////////////////////////////////////////////////////
//
// MAIN FRAME (SchedProjFrame)
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
	// The frame menu commands
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnNewList(wxCommandEvent& event); // This should aim to create a new list

	void OnEnable(wxCommandEvent& event);


	// initializing the book: add all pages to it
	// [Dean Tapit: since this program really only wants to create a notebook, and not pages of widgets, this may change]
	void InitBook();

	// return the currently selected page (never NULL)
	SchedProjPage *CurrentPage();

private:
	// the panel containing everything
	wxPanel *m_panel;

	// the book containing the test pages (the widgets); in SchedProj, just a notebook...?; a wxTreebook in actuality
	SchedProjBookCtrl *m_book;

	// any class wishing to process wxWidgets events must use this macro
	wxDECLARE_EVENT_TABLE();
};