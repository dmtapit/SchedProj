#include "main.h"
//#include "CellSheet.h"

IMPLEMENT_APP(SchedProjApp)

bool SchedProjApp::OnInit()
{
	//CellSheet *cs = new CellSheet(wxT("CellSheet"));
	//cs->Show(true);

	BasicFrame *frame = new BasicFrame(wxT("Basic"), 50, 50, 450, 300);

	frame->Show(true);
	SetTopWindow(frame);
	return true;
}

BasicFrame::BasicFrame(const wxChar *title, int xpos, int ypos, int width, int height)
	: wxFrame((wxFrame*)NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
{
	// Pointer safety.  Always initialize any pointer you have declared in an interface file.
	theText = (wxTextCtrl *)NULL;
	menuBar = (wxMenuBar *)NULL;
	fileMenu = (wxMenu *)NULL;
	
	theText = new wxTextCtrl(this, -1, wxString("stringstringstrginstring\n\n"
		"More string."), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	
	fileMenu = new wxMenu;
	fileMenu->Append(BASIC_OPEN, wxT("&Open File"), wxT("Open an existing file"));
	fileMenu->Append(BASIC_ABOUT, wxT("&About"), wxT("Who wrote this!"));
	fileMenu->AppendSeparator();
	fileMenu->Append(BASIC_EXIT, wxT("E&xit"), wxT("Stop wasting time."));

	menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, wxT("&File"));
	SetMenuBar(menuBar);
	CreateStatusBar(3);
}

BasicFrame::~BasicFrame() {}

BEGIN_EVENT_TABLE (BasicFrame, wxFrame)
	EVT_MENU (BASIC_OPEN, BasicFrame::OnOpenFile)
	EVT_MENU (BASIC_ABOUT, BasicFrame::OnAbout)
	EVT_MENU (BASIC_EXIT, BasicFrame::OnExit)
END_EVENT_TABLE()

void BasicFrame::OnOpenFile(wxCommandEvent & event)
{
	theText->LoadFile(wxT("data.txt"));
}

void BasicFrame::OnAbout(wxCommandEvent & event)
{
	wxString t = TITLE; //TITLE from main.h
	t.append(wxT("\nDB 2001"));

	wxMessageDialog aboutDialog(this, t, wxT("About Basic"), wxOK | wxCANCEL);
	aboutDialog.ShowModal();
}

void BasicFrame::OnExit(wxCommandEvent & event)
{
	Close(true);
}