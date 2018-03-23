#pragma once
#include <wx/dialog.h>
#include <wx/textctrl.h>

class BasicDialog : public wxDialog
{
public:
	BasicDialog(wxWindow * parent, wxWindowID id, const wxString & title,
		const wxPoint & pos = wxDefaultPosition,
		const wxSize & size = wxDefaultSize,
		long style = wxDEFAULT_DIALOG_STYLE);

	wxTextCtrl * dialogText;
	wxString GetText();


	wxTextCtrl * getDialogText() { return dialogText; }

private:
	void OnOk(wxCommandEvent & event);

	DECLARE_EVENT_TABLE()
};