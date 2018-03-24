#include "BasicDialog.h"
#include "main.h" // For AUTHOR
#include <wx/dialog.h>

BasicDialog::BasicDialog(wxWindow * parent, wxWindowID id, const wxString & title, 
						 const wxPoint & position, const wxSize & size, long style) 
	: wxDialog(parent, id, title, position, size, style)
{
	/*NO Sizer used example*/
	/**
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

	//dialogText->AppendText(wxT("Cool"));
	**/

	wxString theTextData = "";
	// Anything added to this container will be added in the vertical orientation
	wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);

	theTextData.append(wxString(
		"Thou art, indeed, just O Lord if I contend with Thee.\n"
		"But sir: what I plead is just.\n"
		"Why do sinner's ways prosper?\n"
		"And why does disappointment all I endeavour end?\n"
		"Wert Thou my enemy, O Thou my friend,\n"
		"How wouldst Thou defeat and thwart me.\n\n"
	));

	dialogText = new wxTextCtrl(this, wxID_ANY, theTextData, wxDefaultPosition, wxSize(150, 100), wxTE_MULTILINE);
	dialogText->SetBackgroundColour(wxColour(0, 0, 0));
	dialogText->SetForegroundColour(wxColour(255, 255, 255));

	topsizer->Add(dialogText, 1, wxEXPAND | wxALL, 10);
	// second argument, 1: indicates that the size of the control can change in the orientation of the
	// sizer, that is, the text control will change its vertical size as the top sizer is resized


	wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
	button_sizer->Add(new wxButton(this, wxID_OK, wxT("OK")), 0, wxALL, 10);
	button_sizer->Add(new wxButton(this, wxID_CANCEL, wxT("Cancel")), 0, wxALL, 10);

	// second argument, 0: retain default sizes
	topsizer->Add(button_sizer, 0, wxALIGN_CENTER);
	SetAutoLayout(TRUE); // Method inherited from the wxWindow class via the wxDialog class
	SetSizer(topsizer); // Tells dialog that it is now the owner of the sizer
	topsizer->Fit(this); // Directs the dialog to size itself around the topsizer
	topsizer->SetSizeHints(this); // Directs the sizer to set the minimal size of the window to match the sizer's minimal size. It has nothing to do with hints!
	
	Center();
}

bool BasicDialog::Validate()
{
	return true;
}

void BasicDialog::OnOk(wxCommandEvent & event)
{
	event.Skip();
}

// CURRENTLY HAS NO KNOWN WORKING FUNCTION...
wxString BasicDialog::GetText()
{
	wxString textToReturn;
	textToReturn = wxT("RETURNED TEXT!");
	return textToReturn;
}

BEGIN_EVENT_TABLE(BasicDialog, wxDialog)
	EVT_BUTTON(wxID_OK, BasicDialog::OnOk)
END_EVENT_TABLE()