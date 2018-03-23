#include "BasicDialog.h"
#include "main.h" // For AUTHOR
#include <wx/dialog.h>

BasicDialog::BasicDialog(wxWindow * parent, wxWindowID id, const wxString & title, 
						 const wxPoint & position, const wxSize & size, long style) 
	: wxDialog(parent, id, title, position, size, style)
{
	wxString dimensions = "", s;
	wxPoint p;
	wxSize sz;

	sz.SetWidth(size.GetWidth() - 20);
	sz.SetHeight(size.GetHeight() - 70);

	p.x = 6; p.y = 2;
	s.Printf(wxT(" x = %d y = %d\n"), p.x, p.y);
	dimensions.append(s);
	s.Printf(wxT(" width = %d height = %d\n"), sz.GetWidth(), sz.GetHeight());
	dimensions.append(s);
	dimensions.append(AUTHOR);

	dialogText = new wxTextCtrl(this, -1, dimensions, p, sz, wxTE_MULTILINE);

	p.y += sz.GetHeight() + 10;
	wxButton * b = new wxButton(this, wxID_OK, wxT("OK"), p, wxDefaultSize);
	p.x += 110;
	wxButton * c = new wxButton(this, wxID_CANCEL, wxT("Cancel"), p, wxDefaultSize);
}

void BasicDialog::OnOk(wxCommandEvent & event)
{
	
}

wxString BasicDialog::GetText()
{
	wxString textToReturn;
	textToReturn = wxT("RETURNED TEXT!");
	return textToReturn;
}

BEGIN_EVENT_TABLE(BasicDialog, wxDialog)
	EVT_BUTTON(wxID_OK, BasicDialog::OnOk)
END_EVENT_TABLE()