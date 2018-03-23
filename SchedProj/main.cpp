#include "main.h"
#include <wx/filename.h>
#include <wx/fontdata.h>
#include <wx/fontdlg.h>
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
	fileMenu->Append(BASIC_FONT, wxT("&Font"), wxT("Change the damn font!"));
	fileMenu->Append(BASIC_DIR, wxT("&Choose Folder"),  wxT("Choose a directory."));
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
	EVT_MENU (BASIC_FONT, BasicFrame::OnChooseFont)
	EVT_MENU (BASIC_DIR, BasicFrame::OnChooseDir)
END_EVENT_TABLE()

void BasicFrame::OnOpenFile(wxCommandEvent & event)
{
	wxFileDialog* openFileDialog = new wxFileDialog(this, wxT("Open file"), "", "", FILETYPES, wxFD_OPEN, wxDefaultPosition);

	if (openFileDialog->ShowModal() == wxID_OK)
	{
		wxString path;
		path.append(openFileDialog->GetDirectory());
		path.append(wxFileName::GetPathSeparator());
		path.append(openFileDialog->GetFilename());
		theText->LoadFile(path);
		SetStatusText(path, 0);
		SetStatusText(openFileDialog->GetDirectory(), 1);
	}
	//theText->LoadFile(wxT("data.txt"));
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

void BasicFrame::OnChooseFont(wxCommandEvent & event)
{
	wxFontData fontData;
	wxFont theFont;
	wxColour colour;

	theFont = theText->GetFont();
	fontData.SetInitialFont(theFont);
	colour = theText->GetForegroundColour();
	fontData.SetColour(colour);
	fontData.SetShowHelp(true);

	wxFontDialog *dialog = new wxFontDialog(this);
	if (dialog->ShowModal() == wxID_OK)
	{
		fontData = dialog->GetFontData();
		theFont = fontData.GetChosenFont();
		theText->SetFont(theFont);
		theText->SetForegroundColour(fontData.GetColour());
	}
}

void BasicFrame::OnChooseDir(wxCommandEvent & event)
{
	wxDirDialog *d = new wxDirDialog(this, wxT("Choose a directory"), "", 0, wxDefaultPosition);

	if (d->ShowModal() == wxID_OK)
	{
		SetCurrentDirectory(d->GetPath());
	}

}