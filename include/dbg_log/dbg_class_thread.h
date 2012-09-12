#ifndef __DBG_LOG_DBG_CLASS_THREAD_H__
#define __DBG_LOG_DBG_CLASS_THREAD_H__

#include "dbg_log/dbg_log_defs.h"
#include "dbg_log/inttypes.h"

#include <string>

namespace dbg_log
{

class DBG_LOG_API dbg_class_thread
{
public:
	dbg_class_thread();
	virtual ~dbg_class_thread();

	void SetName(const std::string &name);
	const std::string &GetName();

	void SetId(uint64_t id);
	uint64_t GetId();

	int GetDepth();
	void SetDepth(int depth);
	void IncDepth();
	void DecDepth();

protected:
	std::string m_name;
	uint64_t m_id;
	int m_depth;

};

}

#endif
