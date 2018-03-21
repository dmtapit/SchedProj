#include "CellSheet.h"

CellSheet::CellSheet(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 350))
{
	wxNotebook *nb = new wxNotebook(this, -1, wxPoint(-1, -1), wxSize(-1, -1), wxNB_BOTTOM);

	wxMenuBar *menubar = new wxMenuBar;
	wxMenu *file = new wxMenu;
	file->Append(wxID_EXIT, wxT("Quit"), wxT(""));
	menubar->Append(file, wxT("&File"));
	SetMenuBar(menubar);

	Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(CellSheet::OnQuit));

	Grid *g1 = new Grid(nb);
	Grid *g2 = new Grid(nb);
	Grid *g3 = new Grid(nb);

	nb->AddPage(g1, wxT("Sheet1"));
	nb->AddPage(g2, wxT("Sheet2"));
	nb->AddPage(g3, wxT("Sheet3"));

	CreateStatusBar();
	Center();
	//Centre();
}

void CellSheet::OnQuit(wxCommandEvent& event)
{
	Close(true);
}

Grid::Grid(wxNotebook *parent) : wxGrid(parent, wxID_ANY)
{
	CreateGrid(10, 10);
	SetRowLabelSize(25);
	SetColLabelSize(12);
	SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
	SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

	for (int i = 0; i < 10; i++) {
		this->SetRowSize(i, 12);
	}
}