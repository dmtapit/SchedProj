///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		NotebookSoul.cpp
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off the wxWidgets sample "notebook.cpp"
//			One could say, it is practically the soul of it...
//			Since the headers were included in the original file,
//			I decided to try to keep consistent with having separate
//			header and class files (implementation).
///////////////////////////////////////////////////////////////////////

#include "NotebookSoul.h"

NotebookSoulPage::NotebookSoulPage(wxTreebook *book, wxImageList *imaglist, const char *const icon[])
	:SoulPage(book, imaglist, icon)
{

}