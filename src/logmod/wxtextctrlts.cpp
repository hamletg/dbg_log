#include "logmod/logmod_prec.h"
#include "logmod/logmod_defs.h"

#include "logmod/wxtextctrlts.h"

namespace logmod
{

wxTextCtrlTS::wxTextCtrlTS(wxWindow* parent,wxWindowID id,const wxString& value,const wxPoint& pos, const wxSize& size, long style)
	: wxTextCtrl(parent,id,value,pos,size,style), m_bufsize(1024)
{
	m_count=0;
	m_buffer=new char[m_bufsize];
}

wxTextCtrlTS::~wxTextCtrlTS()
{
	if (m_buffer!=NULL)
		delete m_buffer;
}

int wxTextCtrlTS::overflow(int i)
{
	int doit=0;

//	AppendText((wxChar)i);
	if (m_count<m_bufsize-1) 
	{
		m_buffer[m_count]=i;
		m_count++;
		if (i=='\n') 
		{
			m_buffer[m_count]=0;
			//AppendText(m_buffer);
			doit=1;
			m_count=0;
		}
	}
	else
	{
		m_buffer[m_count]=i;
		m_buffer[m_count+1]=0;
		//AppendText(m_buffer);
		doit=1;
		m_count=0;
	}

	if (doit)
	{
		bool ismain=wxThread::IsMain();

		if (!ismain) wxMutexGuiEnter();
		AppendText(wxString(m_buffer, wxConvUTF8));
		if (!ismain) wxMutexGuiLeave();
	} 
	
    // return something different from EOF
    return 0;
}

int wxTextCtrlTS::sync()
{
	return 0;
}

std::streamsize wxTextCtrlTS::xsputn(const char_type * s,std::streamsize count)
{
	std::streambuf::xsputn(s,count);
	return count;
}

void wxTextCtrlTS::SetBufSize(int size)
{
	if (m_buffer!=NULL)
		delete m_buffer;
	m_buffer=new char[size];
	m_bufsize=size;
}

int wxTextCtrlTS::GetBufSize()
{
	return m_bufsize;
}

}
