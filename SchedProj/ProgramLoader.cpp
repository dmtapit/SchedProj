#include "ProgramLoader.h"
#include "BasicFrame.h"

ProgramLoader::ProgramLoader(const wxChar *title, int xpos, int ypos, int width, int height)
	: wxFrame((wxFrame*)NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
{
	menuBar = (wxMenuBar *)NULL;
	fileMenu = (wxMenu *)NULL;

	fileMenu = new wxMenu;
	fileMenu->Append(LOAD_PROGRAM, wxT("Initiate a program"), wxT("Choose from a selection of programs"));

	menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, wxT("&File"));
	SetMenuBar(menuBar);
	CreateStatusBar(2);

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	wxPanel *panel = new wxPanel(this, -1);
	
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	
	btnPanel = new ButtonPanel(panel);
	hbox->Add(btnPanel, 2, wxEXPAND | wxRIGHT, 10);

	panel->SetSizer(hbox);

	Center();
}

BEGIN_EVENT_TABLE(ProgramLoader, wxFrame)
EVT_MENU(LOAD_PROGRAM, ProgramLoader::OnLoadProgram)
END_EVENT_TABLE()

void ProgramLoader::OnLoadProgram(wxCommandEvent & event)
{
	
	
}

ButtonPanel::ButtonPanel(wxPanel * parent) : wxPanel(parent, wxID_ANY)
{
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	btn_Basic = new wxButton(this, BASIC_APPLICATION, wxT("Basic Application"));

	Connect(BASIC_APPLICATION, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ButtonPanel::OnBasicDialog));

	vbox->Add(btn_Basic);

	SetSizer(vbox);
}


/*
	When the Basic Application button is clicked, it opens a new window (program) of BasicFrame
*/
void ButtonPanel::OnBasicDialog(wxCommandEvent& event)
{
	BasicFrame *frame = new BasicFrame(wxT("BASIC APP"), 50, 50, 450, 300);
	frame->Show(true);
}