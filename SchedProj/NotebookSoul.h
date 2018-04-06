///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		NotebookSoul.h
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off the wxWidgets sample "notebook.cpp"
//			One could say, it is practically the soul of it...
//			Since the headers were included in the original file,
//			I decided to try to keep consistent with how I already coded
//			initially by having separate header and class files.
///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  headers 
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>
#include <wx/treebook.h>
#include "SchedProjFrame.h" // for SchedProjPage ; // essentially this codes widgets.h/widgets.cpp??

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  constants 
//////////////////////////////////////////////////////////////////////////////////////////////////////

// [ control ids ]
enum
{
	NotebookPage_Reset = wxID_HIGHEST + 1,

	BookPage_Book
};

// [ book orientations ]
enum Orient
{
	Orient_Top,
	Orient_Bottom,
	Orient_Left,
	Orient_Right,
	Orient_Max
};

//////////////////////////////////////
//
// NotebookSoulPage
//
//////////////////////////////////////

class NotebookSoulPage : public SchedProjPage
{
public:
	NotebookSoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[]);
	virtual ~NotebookSoulPage();

	// [Dean Tapit] *GetWidget derived from SchedProjFrame.h *GetWidget (the use of virtual functions!)
	virtual wxWindow *GetWidget() const wxOVERRIDE { return m_book; }
	virtual void RecreateWidget() wxOVERRIDE { RecreateBook(); }
	// wxOVERRIDE does override a base class member
	// In this case, derived class NotebookSoulPage overrides base class SchedProjPage

	// lazy creation of the content // [Dean Tapit] Content of the window I assume
	// wxOVERRIDE the CreateContent() method in SchedProjPage
	virtual void CreateContent() wxOVERRIDE;

protected:
	// [ EVENT HANDLERS ] ///////////////////////////////////////////////
	void OnButtonReset(wxCommandEvent& event);




	// Reset Book parameters
	void Reset();

	// (Re)create book
	void RecreateBook();
	virtual wxBookCtrlBase *CreateBook(long flags) = 0;

	// create or destroy the image list
	//void CreateImageList();

	// create a new page
	wxWindow *CreateNewPage();

	// get the image index for the new page
	int GetIconIndex() const;

	// Controls //////////////////////////

	// the check/radio boxes for styles
	wxCheckBox *m_chkImages;
	wxRadioBox *m_radioOrient;

	// the text controls containing input for various commands
	wxTextCtrl *m_textInsert,
		*m_textRemove,
		*m_textSelect;
	
	// the notebook itself and the sizer it is in
	wxBookCtrlBase *m_book;
	wxSizer *m_sizerBook;

	// the image list for the notebook
	wxImageList *m_imageList;

private:
	wxDECLARE_EVENT_TABLE();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ Event Table ]
//////////////////////////////////////////////////////////////////////////////////////////////////////

wxBEGIN_EVENT_TABLE(NotebookSoulPage, SchedProjPage)
	EVT_BUTTON(NotebookPage_Reset, NotebookSoulPage::OnButtonReset)
wxEND_EVENT_TABLE()