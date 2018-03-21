#include "main.h"
#include "CellSheet.h"

IMPLEMENT_APP(SchedProjApp)

bool SchedProjApp::OnInit()
{
	CellSheet *cs = new CellSheet(wxT("CellSheet"));
	cs->Show(true);

	return true;
}