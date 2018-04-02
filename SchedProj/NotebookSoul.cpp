///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		NotebookSoul.cpp
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off the wxWidgets sample "notebook.cpp"
//			One could say, it is practically the soul of it...
//			Since the headers were included in the original file,
//			I decided to try to keep consistent with having separate
//			header and class files (implementation).
///////////////////////////////////////////////////////////////////////

#include "NotebookSoul.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ IMPLEMENTATION ]
//////////////////////////////////////////////////////////////////////////////////////////////////////

NotebookSoulPage::NotebookSoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[])
	:SoulPage(book, imaglist, icon)
{
	// Initializing everything (the check/radio boxes, the notebook and sizer, and the image list
	m_chkImages = NULL;
	m_radioOrient = NULL;
	
	m_book = NULL;
	m_sizerBook = (wxSizer *)NULL;

	m_imageList = NULL;
}

void NotebookSoulPage::CreateContent()
{
	wxSizer *sizerTop = new wxBoxSizer(wxHORIZONTAL);

	// Left pane
	wxStaticBox *box = new wxStaticBox(this, wxID_ANY, wxT("&Set style"));

	// Middle pane

	// Right pane


	// Final initializations // Check to see what these actually do later

	SetSizer(sizerTop);
}

NotebookSoulPage::~NotebookSoulPage() { //delete m_imagelist; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ OPERATIONS ]
//////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ EVENT HANDLERS ]
//////////////////////////////////////////////////////////////////////////////////////////////////////

void NotebookSoulPage::OnButtonReset(wxCommandEvent& WXUNUSED(event))
{
	//Reset();

	//RecreateBook();
}