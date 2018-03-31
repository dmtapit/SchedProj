///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		NotebookSoul.h
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off the wxWidgets sample "notebook.cpp"
//			One could say, it is practically the soul of it...
//			Since the headers were included in the original file,
//			I decided to try to keep consistent with how I already coded
//			initially by having separate header and class files.
///////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>
#include <wx/treebook.h>
#include "SoulPage.h"

//////////////////////////////////////
//
// NotebookSoulPage
//
//////////////////////////////////////

class NotebookSoulPage : public SoulPage
{
public:
	NotebookSoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[]);
	virtual ~NotebookSoulPage();

protected:

private:
	wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(NotebookSoulPage, SoulPage)

wxEND_EVENT_TABLE()