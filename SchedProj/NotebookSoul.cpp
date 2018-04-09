///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		NotebookSoul.cpp
// Author:		Dean Tapit
// Last Edit:	4/9/18
// Info:		Based off the wxWidgets sample "notebook.cpp"
//			One could say, it is practically the soul of it...
//			Since the headers were included in the original file,
//			I decided to try to keep consistent with having separate
//			header and class files (implementation).
///////////////////////////////////////////////////////////////////////

#include "NotebookSoul.h"

#include "wx/artprov.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ IMPLEMENTATION ]
//	NotebookSoulPage = BookWidgetsPage
//////////////////////////////////////////////////////////////////////////////////////////////////////

NotebookSoulPage::NotebookSoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[])
	:SchedProjPage(book, imaglist, icon)
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

	// must be in sync with Orient enum
	wxArrayString orientations;
	orientations.Add(wxT("&top"));
	orientations.Add(wxT("&bottom"));
	orientations.Add(wxT("&left"));
	orientations.Add(wxT("&right"));

	//wxASSERT_MSG((...........)

	m_chkImages = new wxCheckBox(this, wxID_ANY, wxT("Show &images"));
	m_radioOrient = new wxRadioBox(this, wxID_ANY, wxT("&Tab orientation"),
		wxDefaultPosition, wxDefaultSize,
		orientations, 1, wxRA_SPECIFY_COLS);

	wxSizer *sizerLeft = new wxStaticBoxSizer(box, wxVERTICAL);
	sizerLeft->Add(m_chkImages, 0, wxALL, 5);
	sizerLeft->Add(5, 5, 0, wxGROW | wxALL, 5); // spacer
	sizerLeft->Add(m_radioOrient, 0, wxALL, 5);

	wxButton *btn = new wxButton(this, NotebookPage_Reset, wxT("&Reset"));
	sizerLeft->Add(btn, 0, wxALIGN_CENTRE_HORIZONTAL | wxALL, 15);

	// Middle pane
	wxStaticBox *box2 = new wxStaticBox(this, wxID_ANY, wxT("&Contents"));
	wxSizer *sizerMiddle = new wxStaticBoxSizer(box2, wxVERTICAL);

	wxTextCtrl *text;
	wxSizer *sizerRow = CreateSizerWithTextAndLabel(wxT("Number of pages: "), BookPage_NumPagesText, &text);
	text->SetEditable(false); // [Dean Tapit] For actual use, set to true, I'm guessing...
	sizerMiddle->Add(sizerRow, 0, wxALL | wxGROW, 5);

	sizerRow = CreateSizerWithTextAndLabel(wxT("Current selection: "), BookPage_CurSelectText, &text);
	text->SetEditable(false);
	sizerMiddle->Add(sizerRow, 0, wxALL | wxGROW, 5);

	sizerRow = CreateSizerWithTextAndButton(BookPage_SelectPage, wxT("&Select page"), BookPage_SelectText, &m_textSelect);
	sizerMiddle->Add(sizerRow, 0, wxALL | wxGROW, 5);

	btn = new wxButton(this, BookPage_AddPage, wxT("&Add page"));
	sizerMiddle->Add(btn, 0, wxALL | wxGROW, 5);

	sizerRow = CreateSizerWithTextAndButton(BookPage_InsertPage, wxT("&Insert page at"), BookPage_InsertText, &m_textInsert);
	sizerMiddle->Add(sizerRow, 0, wxALL | wxGROW, 5);
	
	sizerRow = CreateSizerWithTextAndButton(BookPage_RemovePage, wxT("&Remove page"), BookPage_RemoveText, &m_textRemove);
	sizerMiddle->Add(sizerRow, 0, wxALL | wxGROW, 5);

	btn = new wxButton(this, BookPage_DeleteAll, wxT("&Delete All"));
	sizerMiddle->Add(btn, 0, wxALL | wxGROW, 5);

	// Right pane
	m_sizerBook = new wxBoxSizer(wxHORIZONTAL);

	// The three (3) panes compose the whole window
	sizerTop->Add(sizerLeft, 0, wxGROW | (wxALL & ~wxLEFT), 10);
	sizerTop->Add(sizerMiddle, 0, wxGROW | wxALL, 10); // middle pane
	sizerTop->Add(m_sizerBook, 1, wxGROW | (wxALL & ~wxRIGHT), 10);

	RecreateBook();

	// Final initializations // Check to see what these actually do later
	Reset();
	//CreateImageList();

	SetSizer(sizerTop);
}

NotebookSoulPage::~NotebookSoulPage()
{ 
	delete m_imageList; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ OPERATIONS ]
//////////////////////////////////////////////////////////////////////////////////////////////////////

void NotebookSoulPage::Reset()
{
	m_chkImages->SetValue(true);
	m_radioOrient->SetSelection(Orient_Top);
}

void NotebookSoulPage::CreateImageList()
{
	if (m_chkImages->GetValue())
	{
		if (!m_imageList)
		{
			// create a dummy image list with a few icons
			m_imageList = new wxImageList(32, 32);
			wxSize size(32, 32);
			m_imageList->Add(wxArtProvider::GetIcon(wxART_INFORMATION, wxART_OTHER, size));
		}

		if (m_book)
			m_book->SetImageList(m_imageList);
	}
	else // no images
	{
		wxDELETE(m_imageList);
	}

	// [Dean Tapit]: A bug? Is this why I am having problems?

	// because of the bug in wxMSW we can't use SetImageList(NULL) - although
	// it would be logical if this removed the image list from book, under
	// MSW it crashes instead - FIXME
}

void NotebookSoulPage::RecreateBook()
{
	// do not recreate anything in case page content was not prepared yet
	if (!m_radioOrient)
		return;

	int flags = GetAttrs().m_defaultFlags; // Currently only contains border flags

	switch (m_radioOrient->GetSelection())
	{
	default:
		wxFAIL_MSG(wxT("unknown orientation"));
		// fall through

	case Orient_Top:
		flags |= wxBK_TOP;
		break;

	case Orient_Bottom:
		flags |= wxBK_BOTTOM;
		break;

	case Orient_Left:
		flags |= wxBK_LEFT;
		break;

	case Orient_Right:
		flags |= wxBK_RIGHT;
		break;
	}

	wxBookCtrlBase *oldBook = m_book;

	m_book = CreateBook(flags);

	//CreateImageList();

	if (oldBook)
	{
		const int sel = oldBook->GetSelection();

		const int count = oldBook->GetPageCount();

		// recreate the pages
		for (int n = 0; n < count; n++)
		{
			m_book->AddPage(CreateNewPage(),
				oldBook->GetPageText(n),
				false,
				m_chkImages->GetValue() ?
				GetIconIndex() : -1);
		}

		m_sizerBook->Detach(oldBook);
		delete oldBook;

		// restore selection
		if (sel != -1)
		{
			m_book->SetSelection(sel);
		}
	}

	m_sizerBook->Add(m_book, 1, wxGROW | wxALL, 5);
	m_sizerBook->SetMinSize(150, 0);
	m_sizerBook->Layout();

}  // End RecreateBook()

////////////////////////////////////////////
// helper functions
////////////////////////////////////////////

int NotebookSoulPage::GetIconIndex() const
{
	if (m_imageList)
	{
		int nImages = m_imageList->GetImageCount();
		if (nImages > 0)
		{
			return m_book->GetPageCount() % nImages;
		}
	}
	return -1;
}

/*
	Used in NotebookSoulPage::RecreateBook()
*/
wxWindow *NotebookSoulPage::CreateNewPage()
{
	return new wxTextCtrl(m_book, wxID_ANY, wxT("I'm a book page"));
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// [ EVENT HANDLERS ]
//////////////////////////////////////////////////////////////////////////////////////////////////////

void NotebookSoulPage::OnButtonReset(wxCommandEvent& WXUNUSED(event))
{
	Reset();

	RecreateBook();
}

#if wxUSE_NOTEBOOK

//#include "icons/notebook.xpm"
#include "wx/notebook.h"

////////////////////////////////////////////
// NotebookWidgetsPage
////////////////////////////////////////////

/*
	This is (finally) what actually contains the widget itself (wxNotebook)
*/
class NotebookWidgetsPage : public NotebookSoulPage
{
public:
	NotebookWidgetsPage(SchedProjBookCtrl *book, wxImageList *imaglist)
		: NotebookSoulPage(book, imaglist, NULL) //, notebook_xpm) // to replace NULL
	{
		RecreateBook();
	}
	virtual ~NotebookWidgetsPage() {}

protected:

	// event handlers
	//void OnPageChanging(wxNotebookEvent& event);
	//void OnPageChanged(wxNotebookEvent& event);

	// (re)create book ([Dean Tapit] Notice how this is a virtual function/ wxOVERRIDE)
	virtual wxBookCtrlBase *CreateBook(long flags) wxOVERRIDE
	{
		return new wxNotebook(this, BookPage_Book, wxDefaultPosition, wxDefaultSize, flags);
	}

private:
	//wxDECLARE_EVENT_TABLE();
	DECLARE_WIDGETS_PAGE(NotebookWidgetsPage)
};

#if defined(__WXUNIVERSAL__)
#define FAMILY_CTRLS UNIVERSAL_CTRLS
#elif defined(__WXMOTIF__)
#define FAMILY_CTRLS GENERIC_CTRLS
#else
#define FAMILY_CTRLS ALL_CTRLS
#endif


// [Dean Tapit] : why is it necessary to add BOOK_CTRLS? what exactly is FAMILY_CTRLS?
IMPLEMENT_WIDGETS_PAGE(NotebookWidgetsPage, wxT("Notebook"), FAMILY_CTRLS | BOOK_CTRLS);

// void NotebookSoulPage::OnPageChanging(wxNotebookEvent& event)

// void NotebookSoulPage::OnPageChanged(wxNotebookEvent& event)


#endif // wxUSE_NOTEBOOK