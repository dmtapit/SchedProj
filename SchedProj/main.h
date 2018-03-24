#pragma once
#include <wx/wx.h>

static const wxChar *TITLE = wxT("Title of the App Under Construction");
static const wxChar *FILETYPES = wxT(
	"Text files|*.txt|"
	"C/C++ source files|*.cpp;*.cc;*.c|"
	"C/C++ header files|*.hpp;*.h|"
	"Make files|Mak*;mak*|"
	"Java files|*java|"
	"Hypertext markup files|*html;*htm;*HTML;*HTM|"
	"All files|*.*"
);
static const wxChar *AUTHOR = wxT("Dean Tapit [3/22/2018]");

class SchedProjApp : public wxApp
{
public:
	virtual bool OnInit(); // Overriding the OnInit() method, thus declare it virtual
};