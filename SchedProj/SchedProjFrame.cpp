///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		SchedProjFrame.cpp
// Author:		Dean Tapit
// Last Edit:	4/1/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			This is the MAIN FRAME code for Sched Project.
//			Based off of minimal.cpp sample code.
///////////////////////////////////////////////////////////////////////

#include "main.h"
#include "SchedProjFrame.h"

#include "SoulPage.h"

///////////////////////////////////////////////////////////////////////
// Event tables and other macros for wxWidgets
///////////////////////////////////////////////////////////////////////
wxBEGIN_EVENT_TABLE(SchedProjFrame, wxFrame)
EVT_MENU(Minimal_Quit, SchedProjFrame::OnQuit)
EVT_MENU(Minimal_About, SchedProjFrame::OnAbout)

EVT_MENU(ON_NEW_LIST, SchedProjFrame::OnNewList)
wxEND_EVENT_TABLE()

///////////////////////////////////////////////////////////////////////
//
// MAIN FRAME Construction
//
///////////////////////////////////////////////////////////////////////

SchedProjFrame::SchedProjFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 500))
{

	// set the frame icon
	///	SetIcon(wxICON(sample));

#if wxUSE_MENUS // [Dean Tapit: just realized how awesome these if statements are: they are basically options]
	// create a menu bar
	wxMenuBar *menuBar = new wxMenuBar();

	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(ON_NEW_LIST, "&New List\tAlt-N", "Create a new list");
	fileMenu->AppendSeparator();
	fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");

	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");
	
	// Appending the menus to the menuBar
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");

	// Attaching menu bar to the frame
	SetMenuBar(menuBar);
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



#if wxUSE_STATUSBAR
	CreateStatusBar(2);
	SetStatusText("Sched Proj App: Welcome!");
#endif // wxUSE_STATUSBAR

	Center(); // Centers the window frame to the center of the screen/monitor
}

void SchedProjFrame::InitBook()
{
	// TODO
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
// Event Handlers
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