///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		SoulPage.h
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off the wxWidgets sample "notebook.cpp" as well
//			as the "widgets.h" file.
//			One could say, it is practically the soul of it...
///////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>
#include <wx/treebook.h>

class SoulPage : public wxPanel
{
public:
	SoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[]);


};