#include <wx/wx.h>

// Define a new frame type: this is going to be our main frame
class MyFrame : public wxFrame
{
public:

  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  InitToolBar(void);
  
  void FileSave(wxCommandEvent& event);
  void FileSaveAs(wxCommandEvent& event);
  void FileOpen(wxCommandEvent& event);
  

    // event handlers (these functions should _not_ be virtual)
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

private:
    // any class wishing to process wxWindows events must use this macro
    DECLARE_EVENT_TABLE()
};

