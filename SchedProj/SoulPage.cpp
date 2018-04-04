///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		SoulPage.cpp
// Author:		Dean Tapit
// Last Edit:	4/1/18
// Info:		Based off the wxWidgets sample "widgets.cpp" file.
///////////////////////////////////////////////////////////////////////

#include "SoulPage.h"

#include "SchedProjFrame.h" // for ICON_SIZE

///////////////////////////////////////////////////////////////
// SoulPage
///////////////////////////////////////////////////////////////

SoulPage::SoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[])
	: wxPanel(book, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxNO_FULL_REPAINT_ON_RESIZE | wxCLIP_CHILDREN | wxTAB_TRAVERSAL)
{
	imaglist->Add(wxBitmap(wxImage(icon).Scale(ICON_SIZE, ICON_SIZE)));
}