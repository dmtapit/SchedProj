#include "main.h"
#include "BasicFrame.h"

//#include "CellSheet.h"

IMPLEMENT_APP(SchedProjApp)

bool SchedProjApp::OnInit()
{
	//CellSheet *cs = new CellSheet(wxT("CellSheet"));
	//cs->Show(true);

	BasicFrame *frame = new BasicFrame(wxT("Basic"), 50, 50, 450, 300);

	frame->Show(true);
	SetTopWindow(frame);
	return true;
}