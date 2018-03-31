///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		main.h
// Author:		Dean Tapit
// Last Edit:	3/31/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			Contains the wxApp constructor.
//			Also contains various const variables.
///////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>

static const wxChar *TITLE = wxT("BASIC APPLICATION");
static const wxChar *FILETYPES = wxT(
	"Text files|*.txt|"
	"C/C++ source files|*.cpp;*.cc;*.c|"
	"C/C++ header files|*.hpp;*.h|"
	"Make files|Mak*;mak*|"
	"Java files|*java|"
	"Hypertext markup files|*html;*htm;*HTML;*HTM|"
	"All files|*.*"
);
static const wxChar *AUTHOR = wxT("Dean Tapit (c) Mar 2018");
static const wxChar *ABOUT = wxT(" - Learning some wxWidgets basics from wiki.wxwidgets.org");

static const wxChar *VERSION = wxT("0.0.0.2");

class SchedProjApp : public wxApp
{
public:
	virtual bool OnInit(); // Overriding the OnInit() method, thus declare it virtual
};