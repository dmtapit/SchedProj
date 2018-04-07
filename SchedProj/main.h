///////////////////////////////////////////////////////////////////////
// Program:		SchedProj
// Name:		main.h
// Author:		Dean Tapit
// Last Edit:	4/7/18
// Info:		Based off some wxWidgets tutorials on the wiki
//			Contains the wxApp constructor.
//			Also contains various const variables.
//
//			Added applicable comments from "widgets.cpp" sample code
///////////////////////////////////////////////////////////////////////

#pragma once
#include <wx/wx.h>

static const wxChar *MAIN_TITLE = wxT("PROGRAM LOADER");
static const wxChar *FILETYPES = wxT(
	"Text files|*.txt|"
	"C/C++ source files|*.cpp;*.cc;*.c|"
	"C/C++ header files|*.hpp;*.h|"
	"Make files|Mak*;mak*|"
	"Java files|*java|"
	"Hypertext markup files|*html;*htm;*HTML;*HTM|"
	"All files|*.*"
);
static const wxChar *AUTHOR = wxT("Dean Tapit (c) Apr 2018");
static const wxChar *ABOUT = wxT(" - Learning some wxWidgets basics from wiki.wxwidgets.org");

static const wxChar *VERSION = wxT("0.16");

// Defining a new application type, each program should derive a class from wxApp
class SchedProjApp : public wxApp
{
public:

	// this one is called on application startup and is a good place for the app
	// initialization (doing it here and not in the ctor [Dean Tapit: constructor]
	// allows to have an error return: if OnInit() returns false, the application terminates)
	virtual bool OnInit(); // Overriding the OnInit() method, thus declare it virtual

	//wxOVERRIDE; what does this do for OnInit()?
};