#include <wx/wx.h>
#include <wx/resource.h>
#include "mainfram.hpp"
#include "mondrian.xpm"

// #include <wx/toolbar.h>

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
       : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
    // set the frame icon
    SetIcon(wxICON(mondrian));

    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText("Welcome to Kreuzeln!",1);

    CreateToolBar();//(this, 1000);
    InitToolBar();


    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = wxResourceCreateMenuBar("menubar");
    

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);


}


MyFrame::InitToolBar(void)
{
  wxBitmap pix;
  wxToolBar *toolBar = GetToolBar();

  pix.LoadFile("pixmap/new.xpm", wxBITMAP_TYPE_XPM);
  toolBar->AddTool(5001, pix,wxNullBitmap, FALSE ,-1 ,-1 ,(wxObject*) NULL, "Save", "Start a Game.");

  pix.LoadFile("pixmap/open.xpm", wxBITMAP_TYPE_XPM);
  toolBar->AddTool(5002, pix,wxNullBitmap, FALSE ,-1 ,-1 ,(wxObject*) NULL, "Open", "Open a Game.");

  pix.LoadFile("pixmap/save.xpm", wxBITMAP_TYPE_XPM);
  toolBar->AddTool(5003, pix,wxNullBitmap, FALSE ,-1 ,-1 ,(wxObject*) NULL, "Save", "Save current Game.");

  toolBar->AddSeparator();

  pix.LoadFile("pixmap/print.xpm", wxBITMAP_TYPE_XPM);
  toolBar->AddTool(5011, pix,wxNullBitmap, FALSE ,-1 ,-1 ,(wxObject*) NULL, "Print", "Print current Gameboard.");

  toolBar->AddSeparator();
  
  pix.LoadFile("pixmap/help.xpm", wxBITMAP_TYPE_XPM);
  toolBar->AddTool(5021, pix, wxNullBitmap, FALSE ,-1 ,-1 ,(wxObject*) NULL, "Help", "Browse the documentation");

  toolBar->Realize();
}

void
MyFrame::FileSave(wxCommandEvent& event)
{
  wxFileDialog dialog(this, "Save Game", "", "",
		"Text files (*.txt)|*.txt|Document files (*.doc)|*.doc",
		wxSAVE|wxOVERWRITE_PROMPT);
  dialog.ShowModal();
}

void
MyFrame::FileSaveAs(wxCommandEvent& event)
{
  wxFileDialog dialog(this, "Save Game as", "", "",
		"Text files (*.txt)|*.txt|Document files (*.doc)|*.doc",
		wxSAVE|wxOVERWRITE_PROMPT);
  dialog.ShowModal();
}

void
MyFrame::FileOpen(wxCommandEvent& event)
{
  wxFileDialog dialog(this, "Open Game", "", "",
		"Text files (*.txt)|*.txt|Document files (*.doc)|*.doc",
		wxOPEN);
  dialog.ShowModal();
}


// event handlers

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // TRUE is to force the frame to close
    Close(TRUE);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
  wxDialog dialog(this, -1, "Dialog");
  
  wxBitmap bitmap;
  bitmap.LoadFile("pixmap/xxo.xpm", wxBITMAP_TYPE_XPM);

  dialog.ShowModal();

  
  //  wxMessageBox("This is Kreuzeln\nCopyright (C.) 1999, Christian Schäufler",
  //                 "About Kreuzeln", wxOK | wxICON_INFORMATION, this);
}
