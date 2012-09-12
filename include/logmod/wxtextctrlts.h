#ifndef __LOGMOD_WXTEXTCTRLTS_H
#define __LOGMOD_WXTEXTCTRLTS_H

#include <wx/textctrl.h>

//#define BUFSIZE 255

#if !wxHAS_TEXT_WINDOW_STREAM
#include <iostream>
#endif

namespace logmod
{

class LOGMOD_API wxTextCtrlTS 
	: public wxTextCtrl
#if !wxHAS_TEXT_WINDOW_STREAM
	, public std::streambuf
#endif
{
 public:
	
	wxTextCtrlTS(wxWindow* parent,wxWindowID id,const wxString& value = wxT(""),const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0);
	virtual ~wxTextCtrlTS();

	virtual int overflow(int i);
	virtual int sync();
	virtual std::streamsize xsputn(const char_type * s,std::streamsize count);

	void SetBufSize(int size);
	int GetBufSize();
 protected:
	
	int m_count;
	char *m_buffer;
	int m_bufsize;
};


#if !wxHAS_TEXT_WINDOW_STREAM
class LOGMOD_API wxStreamToTextRedirector
{
private:
    void Init(wxTextCtrlTS *text)
    {
        m_sbufOld = m_ostr.rdbuf();
        m_ostr.rdbuf(text);
    }

public:
    wxStreamToTextRedirector(wxTextCtrlTS *text)
		: m_ostr(std::cout)
    {
        Init(text);
    }

	wxStreamToTextRedirector(wxTextCtrlTS *text, std::ostream *ostr)
        : m_ostr(*ostr)
    {
        Init(text);
    }

    ~wxStreamToTextRedirector()
    {
        m_ostr.rdbuf(m_sbufOld);
    }

private:
    // the stream we're redirecting
	std::ostream&   m_ostr;

    // the old streambuf (before we changed it)
	std::streambuf *m_sbufOld;
};

#endif


}


#endif

