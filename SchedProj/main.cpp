#include "main.h"
#include "ProgramLoader.h"

IMPLEMENT_APP(SchedProjApp)

///////////////////////////////////////////
// Essentially the "Main" method/program
///////////////////////////////////////////
bool SchedProjApp::OnInit()
{
	// Base class initialization method
	if (!wxApp::OnInit()) return false;

	wxString appTitle = TITLE;
	//appTitle.Append(ABOUT);

	ProgramLoader *pl = new ProgramLoader(wxT("CHOOSE A PROGRAM TO LOAD"), 50, 50, 600, 300);
	pl->Show(true);

	SetTopWindow(pl);
	
	return true;
}