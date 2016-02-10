#include <wx/wx.h>
#include <wx/resource.h>
#include <wx/menu.h>

#include "mainfram.hpp"
#include "app.hpp"


// ----------------------------------------------------------------------------
// event tables and other macros for wxWindows
// ----------------------------------------------------------------------------

// the event tables connect the wxWindows events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(120, MyFrame::FileOpen)
  EVT_MENU(140, MyFrame::FileSave)
  EVT_MENU(150, MyFrame::FileSaveAs)
  EVT_MENU(170,  MyFrame::OnQuit)
  EVT_MENU(510, MyFrame::OnAbout)
  EVT_MENU(5002, MyFrame::FileOpen)
  EVT_MENU(5003, MyFrame::FileSave)
  
  //EVT_MENU_HIGHLIGHT(170, MyFrame::OnMenuHighlight)
END_EVENT_TABLE()

// Create a new application object: this macro will allow wxWindows to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also declares the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
IMPLEMENT_APP(MyApp)








