#include "dbg_log/dbg_log_prec.h"

#include "dbg_log/dbg_class_thread.h"

namespace dbg_log
{

dbg_class_thread::dbg_class_thread(): m_id(0), m_depth(0)
{
}

dbg_class_thread::~dbg_class_thread()
{
}

void dbg_class_thread::SetName(const std::string &name)
{
	m_name=name;
}

const std::string &dbg_class_thread::GetName()
{
	return m_name;
}

void dbg_class_thread::SetId(uint64_t id)
{
	m_id=id;
}

uint64_t dbg_class_thread::GetId()
{
	return m_id;
}

int dbg_class_thread::GetDepth()
{
	return m_depth;
}

void dbg_class_thread::SetDepth(int depth)
{
	m_depth=depth;
}

void dbg_class_thread::IncDepth()
{
	m_depth++;
}

void dbg_class_thread::DecDepth()
{
	m_depth--;
}

}

