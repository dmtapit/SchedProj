#include "ProgramLoader.h"

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

	Center();
}

BEGIN_EVENT_TABLE(ProgramLoader, wxFrame)
EVT_MENU(LOAD_PROGRAM, ProgramLoader::OnLoadProgram)
END_EVENT_TABLE()

void ProgramLoader::OnLoadProgram(wxCommandEvent & event)
{

}