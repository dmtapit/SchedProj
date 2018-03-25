#include "ProgramLoader.h"
#include "BasicFrame.h"
#include "CellSheet.h"
#include "BasicDrawPane.h"

ProgramLoader::ProgramLoader(const wxChar *title, int xpos, int ypos, int width, int height)
	: wxFrame((wxFrame*)NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
{
	menuBar = (wxMenuBar *)NULL;
	fileMenu = (wxMenu *)NULL;

	fileMenu = new wxMenu;
	fileMenu->Append(QUIT_PROGRAM, wxT("Close Program Loader"), wxT("This won't close any other open applications."));

	menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, wxT("&File"));
	SetMenuBar(menuBar);
	CreateStatusBar(2);

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	wxPanel *panel = new wxPanel(this, -1);
	
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	
	btnPanel = new ButtonPanel(panel);
	vbox->Add(btnPanel, 3, wxEXPAND | wxALL, 20);

	panel->SetSizer(vbox);
	//btnPanel->SetSizer(vbox); // Interesting result

	Center();
}

BEGIN_EVENT_TABLE(ProgramLoader, wxFrame)
EVT_MENU(QUIT_PROGRAM, ProgramLoader::OnQuit)
END_EVENT_TABLE()

void ProgramLoader::OnQuit(wxCommandEvent & event)
{
	Close(true);
}

ButtonPanel::ButtonPanel(wxPanel * parent) : wxPanel(parent, wxID_ANY)
{
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	btn_Basic = new wxButton(this, BASIC_APPLICATION, wxT("Basic Application"));
	btn_CellSheet = new wxButton(this, CELL_SHEET, wxT("Cell Sheet Application"));
	btn_PanelDraw = new wxButton(this, PANEL_DRAW, wxT("Panel List Application"));

	Connect(BASIC_APPLICATION, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ButtonPanel::OnBasicDialog));
	Connect(CELL_SHEET, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ButtonPanel::OnCellDialog));
	Connect(PANEL_DRAW, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ButtonPanel::OnPanelDrawDialog));

	vbox->Add(btn_Basic);
	vbox->Add(btn_CellSheet);
	vbox->Add(btn_PanelDraw);

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

void ButtonPanel::OnCellDialog(wxCommandEvent& event)
{
	CellSheet *cs = new CellSheet(wxT("Cell Sheet"));
	cs->Show(true);
}

void ButtonPanel::OnPanelDrawDialog(wxCommandEvent& event)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxFrame * frame = new wxFrame((wxFrame *)NULL, -1, wxT("Hello wxDC"), wxPoint(50, 50), wxSize(800, 600));

	BasicDrawPane * drawPane = new BasicDrawPane((wxFrame*)frame);
	sizer->Add(drawPane, 1, wxEXPAND);

	frame->SetSizer(sizer);
	frame->SetAutoLayout(true);

	frame->Show();
}