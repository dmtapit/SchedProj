///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		NotebookSoul.h
// Author:		Dean Tapit
// Last Edit:	4/9/18
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

	BookPage_AddPage,
	BookPage_SelectPage,
	BookPage_SelectText,
	BookPage_InsertPage,
	BookPage_InsertText,
	BookPage_RemovePage,
	BookPage_RemoveText,
	BookPage_DeleteAll,
	BookPage_NumPagesText,
	BookPage_CurSelectText,

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
	void OnButtonAddPage(wxCommandEvent& event);
	void OnButtonSelectPage(wxCommandEvent& event);
	void OnButtonInsertPage(wxCommandEvent& event);
	void OnButtonRemovePage(wxCommandEvent& event);
	void OnButtonDeleteAll(wxCommandEvent& event);

	void OnCheckOrRadioBox(wxCommandEvent& event);




	// Reset Book parameters
	void Reset();

	// (Re)create book
	void RecreateBook();
	virtual wxBookCtrlBase *CreateBook(long flags) = 0;

	// create or destroy the image list
	void CreateImageList();


	// Helper Functions (used in event handlers) /////////////////////////////////////

	// get the image index for the new page
	int GetIconIndex() const;

	// create a new page
	wxWindow *CreateNewPage();

	// get the numeric value of text ctrl
	int GetTextValue(wxTextCtrl *text) const;

	// is the value in range?
	bool IsValidValue(int val) const
	{
		return (val >= 0) && (val < (int)m_book->GetPageCount());
	}

	// Controls //////////////////////////////////////////////////////////////////////

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
// - Connects the ID's with their respective functions
//////////////////////////////////////////////////////////////////////////////////////////////////////

wxBEGIN_EVENT_TABLE(NotebookSoulPage, SchedProjPage)
	EVT_BUTTON(NotebookPage_Reset, NotebookSoulPage::OnButtonReset)
	EVT_BUTTON(BookPage_AddPage, NotebookSoulPage::OnButtonAddPage)
	EVT_BUTTON(BookPage_SelectPage, NotebookSoulPage::OnButtonSelectPage)
	EVT_BUTTON(BookPage_InsertPage, NotebookSoulPage::OnButtonInsertPage)
	EVT_BUTTON(BookPage_RemovePage, NotebookSoulPage::OnButtonRemovePage)
	EVT_BUTTON(BookPage_DeleteAll, NotebookSoulPage::OnButtonDeleteAll)

	EVT_CHECKBOX(wxID_ANY, NotebookSoulPage::OnCheckOrRadioBox)
	EVT_RADIOBOX(wxID_ANY, NotebookSoulPage::OnCheckOrRadioBox)


wxEND_EVENT_TABLE()