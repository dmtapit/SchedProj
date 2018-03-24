#include "BasicFrame.h"
#include "BasicDialog.h"
#include "main.h" // for FILETYPES
#include <wx/filename.h>
#include <wx/fontdata.h>
#include <wx/fontdlg.h>

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
	fileMenu->Append(BASIC_SAVE, wxT("&Save file"), wxT("Save the current file."));
	fileMenu->Append(BASIC_SAVE_AS, wxT("Save as..."), wxT("Save file as ..."));
	fileMenu->Append(BASIC_FONT, wxT("&Font"), wxT("Change the damn font!"));
	fileMenu->Append(BASIC_DIR, wxT("&Choose Folder"), wxT("Choose a directory."));
	fileMenu->AppendSeparator();
	fileMenu->Append(BASIC_ABOUT, wxT("&About"), wxT("Who wrote this!"));
	fileMenu->Append(BASIC_EXIT, wxT("E&xit"), wxT("Stop wasting time."));

	menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, wxT("&File"));
	SetMenuBar(menuBar);
	CreateStatusBar(3);

	Center();
}

BasicFrame::~BasicFrame() {}

BEGIN_EVENT_TABLE(BasicFrame, wxFrame)
EVT_MENU(BASIC_OPEN, BasicFrame::OnOpenFile)
EVT_MENU(BASIC_SAVE, BasicFrame::OnSaveFile)
EVT_MENU(BASIC_SAVE_AS, BasicFrame::OnSaveFileAs)
EVT_MENU(BASIC_FONT, BasicFrame::OnChooseFont)
EVT_MENU(BASIC_DIR, BasicFrame::OnChooseDir)
EVT_MENU(BASIC_ABOUT, BasicFrame::OnAbout)
EVT_MENU(BASIC_EXIT, BasicFrame::OnExit)
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
}

void BasicFrame::OnSaveFile(wxCommandEvent & event)
{
	wxString path;
	theText->SaveFile(path);
	SetStatusText("Saved current file.", 1);
}

void BasicFrame::OnSaveFileAs(wxCommandEvent & event)
{
	wxFileDialog* saveFileDialog = new wxFileDialog(this, wxT("Save file"), "", "", FILETYPES, wxFD_SAVE, wxDefaultPosition);

	if (saveFileDialog->ShowModal() == wxID_OK)
	{
		wxString path;
		path.append(saveFileDialog->GetDirectory());
		path.append(wxFileName::GetPathSeparator());
		path.append(saveFileDialog->GetFilename());
		theText->SaveFile(path);
		SetStatusText("Saved the file successfully!", 0);
		SetStatusText(saveFileDialog->GetDirectory(), 1);
	}
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

/*void BasicFrame::OnAbout(wxCommandEvent & event)
{
wxString t = TITLE; //TITLE from main.h
t.append(wxT("\nDB 2001"));

wxMessageDialog aboutDialog(this, t, wxT("About Basic"), wxOK | wxCANCEL);
aboutDialog.ShowModal();
}
*/

//** This is not working as intended. Where is the logical problem? (Want to append the text, but can't...)
void BasicFrame::OnAbout(wxCommandEvent & event)
{
	BasicDialog aboutDialog(this, -1, wxT("Basic Dialog"), wxPoint(100, 100), wxSize(200, 200));
	if (aboutDialog.ShowModal() == wxID_OK)
		//aboutDialog.dialogText->AppendText(aboutDialog.GetText());
		aboutDialog.dialogText->AppendText(wxT("Reader\nReader\n"));
	else
		aboutDialog.dialogText->AppendText(wxT("The about box was cancelled.\n"));
		
}

void BasicFrame::OnExit(wxCommandEvent & event)
{
	Close(true);
}


/*To be continued from "Creating other frames unfinished tutorial"
void BasicFrame::OnNewFrame(wxCommandEvent & event)
{
	wxString theTitle;
	theTitle = wxGetTextFromUser(wxT("Enter a title"), wxT("Input text"), wxT("NO NAME"), this, -1, -1, true);

	BasicFrame * win = new BasicFrame(theTitle, 150, 150, 450, 300);
	windowList->Append(win);
	win->Show(true);
}
*/