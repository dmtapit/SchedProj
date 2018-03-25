#include "main.h"
#include "ProgramLoader.h"
#include "BasicFrame.h"

//#include "CellSheet.h"

IMPLEMENT_APP(SchedProjApp)

bool SchedProjApp::OnInit()
{
	//CellSheet *cs = new CellSheet(wxT("CellSheet"));
	//cs->Show(true);

	wxString appTitle = TITLE;
	//appTitle.Append(ABOUT);

	//BasicFrame *frame = new BasicFrame(appTitle, 50, 50, 450, 300);
	//frame->Show(true);

	ProgramLoader *pl = new ProgramLoader(wxT("CHOOSE A PROGRAM TO LOAD"), 50, 50, 600, 300);
	pl->Show(true);


	SetTopWindow(pl);
	
	return true;
}