#include "SchedProjFrame.h"
#include "main.h"

//////////////////////////
// MAIN FRAME
//////////////////////////

// frame constructor
SchedProjFrame::SchedProjFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 500))
{
#if wxUSE_MENUS
	// create a menu bar
	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");

	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");
	
	wxMenuBar *menuBar = new wxMenuBar();
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

#if wxUSE_STATUSBAR
	CreateStatusBar(2);
	SetStatusText("Sched Proj App: Welcome!");
#endif // wxUSE_STATUSBAR

	Center(); // Centers the window frame to the center of the screen/monitor
}

// Event tables and other macros for wxWidgets
wxBEGIN_EVENT_TABLE(SchedProjFrame, wxFrame)
	EVT_MENU(Minimal_Quit, SchedProjFrame::OnQuit)
	EVT_MENU(Minimal_About, SchedProjFrame::OnAbout)
wxEND_EVENT_TABLE()



//////////////////////////////
// Event Handlers
//////////////////////////////

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