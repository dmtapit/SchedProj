///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		SchedProjFrame.cpp
// Author:		Dean Tapit
// Last Edit:	4/4/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			This is the MAIN FRAME code for Sched Project.
//			Based off of minimal.cpp sample code.
///////////////////////////////////////////////////////////////////////

#include "main.h"
#include "SchedProjFrame.h"

#include "wx/persist/toplevel.h"

// If one does not want to use separate header(.h) and main(.cpp) files, can probably
// just combine both; so, all the SchedProjFrame.h would go above the code in SchedProjFrame.cpp

// For Some Reason, putting this code in the header file results in:
// SchedProjFrame.obj : error LNK2005: "wchar_t const * * TreebookCategories" (?TreebookCategories@@3PAPB_WA) already defined in ProgramLoader.obj
// C:\Users\Dean Tapit\source\repos\SchedProj\Debug\SchedProj.exe : fatal error LNK1169: one or more multiply defined symbols found
const wxChar *TreebookCategories[MAX_PAGES] = {
	wxT("TREEBOOK_Category")
};

// An Array of Pages (although for this program, perhaps one page is needed for now...)
WX_DEFINE_ARRAY_PTR(SchedProjPage *, ArrayWidgetsPage);


///////////////////////////////////////////////////////////////////////
// Event tables and other macros for wxWidgets
///////////////////////////////////////////////////////////////////////
wxBEGIN_EVENT_TABLE(SchedProjFrame, wxFrame)
EVT_MENU(Minimal_Quit, SchedProjFrame::OnQuit)
EVT_MENU(Minimal_About, SchedProjFrame::OnAbout)
EVT_MENU(ON_NEW_LIST, SchedProjFrame::OnNewList)

EVT_BUTTON(SchedProj_Quit, SchedProjFrame::OnExit)

EVT_MENU(Widgets_Enable, SchedProjFrame::OnEnable)
EVT_MENU(Widgets_Show, SchedProjFrame::OnShow)

wxEND_EVENT_TABLE()

///////////////////////////////////////////////////////////////////////
//
// MAIN FRAME Construction
//
///////////////////////////////////////////////////////////////////////

SchedProjFrame::SchedProjFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 500))
{
	const bool sizeSet = wxPersistentRegisterAndRestore(this, "Main");

	// set the frame icon
	///	SetIcon(wxICON(sample));

#if wxUSE_MENUS // [Dean Tapit: just realized how awesome these if statements are: they are basically options]
	// create a menu bar
	wxMenuBar *menuBar = new wxMenuBar();

	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(ON_NEW_LIST, "&New List\tAlt-N", "Create a new list");
	fileMenu->AppendCheckItem(Widgets_Enable, wxT("&Enable/disable\tCtrl-E"));
	fileMenu->AppendCheckItem(Widgets_Show, wxT("Show/Hide"));
	fileMenu->AppendSeparator();
	fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");

	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");
	
	// Appending the menus to the menuBar
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// Attaching menu bar to the frame
	SetMenuBar(menuBar);

	menuBar->Check(Widgets_Enable, true);
	menuBar->Check(Widgets_Show, true);


#else // !wxUSE_MENUS
	// If menus are not available add a button to access the about box
	wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
	aboutBtn->Bind(wxEVT_BUTTON, &MyFrame::OnAbout, this);
	sizer->Add(aboutBtn, wxSizerFlags().Center());
#endif // wxUSE_MENUS/!wxUSE_MENUS

	// create controls
	m_panel = new wxPanel(this, wxID_ANY);
	wxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);

	// The pane should contain the widget (notebook) to be used.  Based on the original code
	// from "widgets.cpp", the two panes will kept as is for my own learning purposes
	// Can add the rest of the log window code if I want to later

	int style = wxBK_DEFAULT;
	// Uncomment to suppress page theme (draw in solid colour)
	//style |= wxNB_NOPAGETHEME;

	m_book = new SchedProjBookCtrl(m_panel, SchedProj_BookCtrl,
		wxDefaultPosition, wxDefaultSize, style, "SchedProj - Book Ctrl");

	InitBook(); // CODE UNDER CONSTRUCTION

	// Code for the second pane (lower/down) starts here
	// Unlike the "widgets.cpp", no log window will be added for now, just get the notebook going
	// To keep the code from getting too much and hinder my understanding of it, the log portion
	// is kept out. Can add it back in when I think I have gotten the gist of this whole thing...
	// see line 486, "widgets.cpp"
	wxSizer *sizerDown = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer *sizerBtns = new wxBoxSizer(wxHORIZONTAL);
	wxButton *btn;

	btn = new wxButton(m_panel, SchedProj_Quit, wxT("Exit"));
	sizerBtns->Add(btn);
	sizerDown->Add(sizerBtns, 0, wxALL | wxALIGN_RIGHT, 5);

	// Putting everything together
	sizerTop->Add(m_book, 1, wxGROW | (wxALL & ~(wxTOP | wxBOTTOM)), 10);
	sizerTop->Add(0, 5, 0, wxGROW); // spacer in between
	sizerTop->Add(sizerDown, 0, wxGROW | (wxALL & ~wxTOP), 10);

	m_panel->SetSizer(sizerTop);

	// The code below uses a wxPersistentRegisterAndRestore which is from the library "wx/persist/toplevel.h"
	const wxSize sizeMin = m_panel->GetBestSize();
	if (!sizeSet)
		SetClientSize(sizeMin);
	SetMinClientSize(sizeMin);

#if wxUSE_STATUSBAR
	CreateStatusBar(2);
	SetStatusText("Sched Proj App: Welcome!");
#endif // wxUSE_STATUSBAR

	Center(); // Centers the window frame to the center of the screen/monitor
}

/*
	MIGHT NOT NEED THIS SINCE WE ARE NOT REALLY CREATING A BOOK OF WIDGETS LIKE IN THE SAMPLE "widgets.cpp"
	BUT RATHER JUST UTILIZE ONE OF THE WIDGETS...
 */
void SchedProjFrame::InitBook()
{
	// [Dean Tapit] Not implementing the images as of now...
	wxImageList *imageList = new wxImageList(ICON_SIZE, ICON_SIZE);

	//wxImage img(sample_xpm); // What is this, some form of ASCII ART???
	//imageList->Add(wxBitmap(img.Scale(ICON_SIZE, ICON_SIZE)));

#if !USE_TREEBOOK
	SchedProjBookCtrl *books[MAX_PAGES];
#endif

	ArrayWidgetsPage pages[MAX_PAGES]; // Currently should be at '1' (check SchedProjFrame.h) since I only want one widget?
	wxArrayString labels[MAX_PAGES];

	wxMenu *menuPages = new wxMenu;
	unsigned int nPage = 0;
	int cat, imageId = 1;

	// We need to first create all pages and only then add them to the book
	// as we need the image list first
	//
	// we also construct the pages menu during this first iteration
	for (cat = 0; cat < MAX_PAGES; cat++)
	{
#if USE_TREEBOOK
		nPage++; // increase for parent page
#else
		// [Dean Tapit] I won't enter this code now since it will clutter my understanding of the code right now
#endif

		// [Dean Tapit] PAGE INFO FOR LOOP; Will look into this later
		// LOOKS LIKE YOU ARE GOING TO NEED THIS
		for ( WidgetsPageInfo *info = SchedProjPage::ms_widgetPages;
			 info;
			 info = info->GetNext() )
		{
			if ((info->GetCategories() & (1 << cat)) == 0)
				continue;

			SchedProjPage *page = (*info->GetCtor())(
#if USE_TREEBOOK
				m_book
#else
				books[cat]
#endif
				, imageList);
			pages[cat].Add(page);

			labels[cat].Add(info->GetLabel());
			/*
			if (cat == ALL_PAGE)
			{
				menuPages->AppendRadioItem(
					Widgets_GoToPage + nPage,
					info->GetLabel()
				);
#if !USE_TREEBOOK
				// consider only for book in book architecture
				nPage++;
#endif
			}
			*/

#if USE_TREEBOOK
			// consider only for treebook architecture (with subpages)
			nPage++;
#endif
		}
	}

	// [Dean Tapit] Might not need this page menu item...

	//GetMenuBar()->Append(menuPages, wxT("&Page"));

	//m_book->AssignImageList(imageList);

	for (cat = 0; cat < MAX_PAGES; cat++)
	{
#if USE_TREEBOOK
		m_book->AddPage(NULL, TreebookCategories[cat], false, 0);
#else

#endif

		// now do add them [Dean Tapit] Do I need to do this for my purposes??
		size_t count = pages[cat].GetCount();
		for (size_t n = 0; n < count; n++)
		{
#if USE_TREEBOOK
			m_book->AddSubPage
#else
			books[cat]->AddPage
#endif
				(
					pages[cat][n],
					labels[cat][n],
					false, // don't select
					imageId++
					)
				;
		}

	}
	
	// No need for page change?

	// Connect( .... );

	// What exactly does this do?
	// bool pageSet = wxPersistentRegisterAndRestore(m_book);

#if USE_TREEBOOK
	// for treebook page #0 is empty parent page only so select the first page
	// with some contents
	//if (!pageSet)
	//	m_book->SetSelection(1);

	// but ensure that the top of the tree is shown nevertheless
	wxTreeCtrl * const tree = m_book->GetTreeCtrl();

	wxTreeItemIdValue cookie;
	tree->EnsureVisible(tree->GetFirstChild(tree->GetRootItem(), cookie));
#else
	if (!pageSet)
	{
		// for other books set selection twice to force connected event handler
		// to force lazy creation of initiall visible content
		m_book->SetSelection(1);
		m_book->SetSelection(0);
	}
#endif // USE_TREEBOOK

}

SchedProjPage *SchedProjFrame::CurrentPage()
{
	wxWindow *page = m_book->GetCurrentPage();
	return wxStaticCast(page, SchedProjPage);

}

SchedProjFrame::~SchedProjFrame()
{
	// NOTE: The code in SchedProjFrame currently does not utilize a Log window 
	// unlike in the sample code in "widgets.cpp". This code was the only one in it.
#if USE_LOG
	delete m_logTarget;
#endif //USE_LOG
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// SchedProjFrame Event Handlers
//
/////////////////////////////////////////////////////////////////////////////////////////

void SchedProjFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true is to force the frame to close
	Close(true);
}

void SchedProjFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxString::Format("[ SchedProj App %s ]\n"
		"\n"
		"This app is currently under construction...\n"
		"I see you are using %s!"
		"\n"
		"%s", VERSION, wxGetOsDescription(), AUTHOR
	),
		"About SchedProj App", wxOK | wxICON_INFORMATION, this);
}

void SchedProjFrame::OnNewList(wxCommandEvent& event)
{
	//SoulPage = new SoulPage();
}

/////////////////////////////////////////////////////////////////////////////////////////

void SchedProjFrame::OnExit(wxCommandEvent& WXUNUSED(event)) // BUTTON
{
	Close();
}

/////////////////////////////////////////////////////////////////////////////////////////

void SchedProjFrame::OnEnable(wxCommandEvent& event)
{
	SchedProjPage::GetAttrs().m_enabled = event.IsChecked();

	CurrentPage()->SetUpWidget();
}

void SchedProjFrame::OnShow(wxCommandEvent& event)
{
	SchedProjPage::GetAttrs().m_show = event.IsChecked();

	CurrentPage()->SetUpWidget();
}



///////////////////////////////////////////////////////////////////////////////////
// WidgetsPageInfo
///////////////////////////////////////////////////////////////////////////////////

WidgetsPageInfo::WidgetsPageInfo(Constructor ctor, const wxChar *label, int categories)
	: m_label(label)
	, m_categories(categories)
{
	m_ctor = ctor;

	m_next = NULL;

	// dummy sorting: add and immediately sort in the list according to label
	if (SchedProjPage::ms_widgetPages)
	{
		WidgetsPageInfo *node_prev = SchedProjPage::ms_widgetPages;
		if (wxStrcmp(label, node_prev->GetLabel().c_str()) < 0)
		{
			// add as first
			m_next = node_prev;
			SchedProjPage::ms_widgetPages = this;
		}
		else
		{
			WidgetsPageInfo *node_next;
			do
			{
				node_next = node_prev->GetNext();
				if (node_next)
				{
					// add if between two
					if (wxStrcmp(label, node_next->GetLabel().c_str()) < 0)
					{
						node_prev->SetNext(this);
						m_next = node_next;
						// force to break loop
						node_next = NULL;
					}
				}
				else
				{
					// add as last
					node_prev->SetNext(this);
					m_next = node_next;
				}
				node_prev = node_next;
			} while (node_next);
		}
	}
	else
	{
		// add when first
		SchedProjPage::ms_widgetPages = this;
	}
}



///////////////////////////////////////////////////////////////////////////////////
// SchedProjPage
///////////////////////////////////////////////////////////////////////////////////

WidgetsPageInfo *SchedProjPage::ms_widgetPages = NULL;

SchedProjPage::SchedProjPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[])
	: wxPanel(book, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxNO_FULL_REPAINT_ON_RESIZE | wxCLIP_CHILDREN | wxTAB_TRAVERSAL)
{
	//imaglist->Add(wxBitmap(wxImage(icon).Scale(ICON_SIZE, ICON_SIZE)));
}

/* static */
SchedProjAttributes& SchedProjPage::GetAttrs()
{
	static SchedProjAttributes s_attrs;

	return s_attrs;
}

void SchedProjPage::SetUpWidget()
{
	const Widgets widgets = GetWidgets();

	for (Widgets::const_iterator it = widgets.begin();
		it != widgets.end();
		++it)
	{
		wxCHECK_RET(*it, "NULL widget");

		// [Dean Tapit] The Enable and Show methods are part of the library "event.h" !
		(*it)->Enable(GetAttrs().m_enabled);
		(*it)->Show(GetAttrs().m_enabled);

		//(*it)->SetWindowVariant(GetAttrs().m_variant);

		(*it)->Refresh();
	}
}