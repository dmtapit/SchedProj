///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		main.cpp
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			Contains the wxApp initializing "main" function
//			At the moment, it loads a program that can call instances
//			of other programs (classes) that are not tied to each
//			other.
///////////////////////////////////////////////////////////////////////

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

	//wxString appTitle = TITLE;
	//appTitle.Append(ABOUT);

	ProgramLoader *pl = new ProgramLoader(wxT("CHOOSE A PROGRAM TO LOAD"), 50, 50, 600, 300);
	pl->Show(true);

	SetTopWindow(pl);
	
	return true;
}