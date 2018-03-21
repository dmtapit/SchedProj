#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>

class CellSheet : public wxFrame
{
public:
	CellSheet(const wxString& title);
	
	void OnQuit(wxCommandEvent& event);
};

class Grid : public wxGrid
{
public:
	Grid(wxNotebook *parent);
};