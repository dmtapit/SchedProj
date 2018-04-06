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

class WidgetsPageInfo;

// INTRODUCING NEW PAGES DON'T FORGET TO ADD ENTRIES TOO 'WidgetCategories'
// [Dean Tapit] I'm assuming that this means these enums are the labels for the pages
// of the Treebook, where all the widgets can be chosen just as in sample "widgets.cpp"
// My aim at the moment is to just open one widget: the notebook.cpp
enum
{
	// [Dean Tapit] I still don't have a good grasp of most of the code in the "widgets.cpp"
	// sample app.  It is quite interesting, though...
	BOOK_PAGE,
	ALL_PAGE,
	MAX_PAGES = 1
};

enum
{
	BOOK_CTRLS = 1 << BOOK_PAGE,
	ALL_CTRLS = 1 << ALL_PAGE
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
	Widgets_Enable,
	Widgets_Show,
	
	
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

// struct to store common widget attributes (in case I decide to follow "widgets.h" more closely
struct SchedProjAttributes
{
	SchedProjAttributes()
	{
		m_enabled = true;
		m_show = true;

		m_defaultFlags = wxBORDER_DEFAULT;
	}

	bool m_enabled;
	bool m_show;

	// the default flags, currently only contains border flags
	int m_defaultFlags;
};

class SchedProjPage : public wxPanel
{
public:
	SchedProjPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[]);
	
	// return the control shown by this page
	virtual wxWindow *GetWidget() const = 0;
	
	// lazy creation of the content
	virtual void CreateContent() = 0;

	// some pages show additional controls, in this case override this one to 
	// return all of them (including the one returned by GetWidget())
	virtual Widgets GetWidgets() const
	{
		Widgets widgets;
		widgets.push_back(GetWidget());
		return widgets;
	}

	// recreate the control shown by this page
	//
	// this is currently used only to take into account the border flags
	virtual void RecreateWidget() = 0;

	// apply current attributes to the widget(s)
	void SetUpWidget();

	// the default attributes for the widget
	static SchedProjAttributes& GetAttrs();

protected:

public:
	// the head of the linked list containing info about all pages
	static WidgetsPageInfo *ms_widgetPages;

};

///////////////////////////////////////////////////////////////////////
//
// Dynamic SchedProjPage creation helpers
//
///////////////////////////////////////////////////////////////////////

class WidgetsPageInfo
{
public:
	typedef SchedProjPage *(*Constructor)(wxTreebook *book, wxImageList *imaglist);

	// our ctor
	WidgetsPageInfo(Constructor ctor, const wxChar *label, int categories);

	// accessors
	const wxString& GetLabel() const { return m_label; }
	int GetCategories() const { return m_categories; };
	Constructor GetCtor() const { return m_ctor; }
	WidgetsPageInfo *GetNext() const { return m_next; }

	void SetNext(WidgetsPageInfo *next) { m_next = next; }

private:
	// the label of the page
	wxString m_label;

	// the list (flags) for sharing page between categories
	int m_categories;

	// the function to create this page
	Constructor m_ctor;

	// next node in the linked list or NULL
	WidgetsPageInfo *m_next;
};

// to declare a page, this macro must be used in the class declaration
#define DECLARE_WIDGETS_PAGE(classname)										\
	private:																\
		static WidgetsPageInfo ms_info##classname;							\
	public:																	\
		const WidgetsPageInfo *GetPageInfo() const							\
			{ return &ms_info##classname; }

// and this one must be inserted somewhere in the source file
#define IMPLEMENT_WIDGETS_PAGE(classname, label, categories)				\
	SchedProjPage *wxCtorFor##classname(wxTreebook *book,					\
										wxImageList *imaglist)				\
		{ return new classname(book, imaglist); }							\
	WidgetsPageInfo classname::												\
		ms_info##classname(wxCtorFor##classname, label, ALL_CTRLS | categories)


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

protected:
	// event handlers (these functions should not be virtual)
	// The frame menu commands
	void OnQuit(wxCommandEvent& event); // File menu quit
	void OnAbout(wxCommandEvent& event);
	void OnNewList(wxCommandEvent& event); // This should aim to create a new list

	void OnExit(wxCommandEvent& event); // Button quit

	void OnEnable(wxCommandEvent& event);
	void OnShow(wxCommandEvent& event);

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