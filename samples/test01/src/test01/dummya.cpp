#include "test01/test01_prec.h"
#include "test01/dummya.h"

#include "dbg_log/dbg_class.h"
#ifndef _MSC_VER
#include "dbg_log/config.h"
#endif

DummyA::DummyA()
{
}

DummyA::~DummyA()
{
}

void DummyA::Call()
{
	DBG_CALLMEMBER("DummyA::Call",false);
    DBG_CALLMEMBER_END;
}

void DummyA::Call(int param1)
{
	DBG_CALLMEMBER("DummyA::Call(int param1)",false);
    DBG_PARAM(0,"p1",int,param1);
    DBG_CALLMEMBER_END;
}

void DummyA::Call(int param1, int param2)
{
	DBG_CALLMEMBER("DummyA::Call",false);
	DBG_PARAM(0,"p1",int,param1);
	DBG_PARAM(1,"p2",int,param1);
    DBG_CALLMEMBER_END;
}

void DummyA::Call(int param1, int param2, int param3)
{
	DBG_CALLMEMBER("DummyA::Call",false);
	DBG_PARAM(0,"p1",int,param1);
	DBG_PARAM(1,"p2",int,param2);
	DBG_PARAM(2,"p2",int,param3);
    DBG_CALLMEMBER_END;
}

int DummyA::CallR()
{
	DBG_CALLMEMBER_RET("DummyA::CallR",false,int,result);
	DBG_CALLMEMBER_END;

	result=1;
	return result;
}

int DummyA::CallR(int param1)
{
	DBG_CALLMEMBER_RET("DummyA::CallR",false,int,result);
	DBG_PARAM(0,"p1",int,param1);
	DBG_CALLMEMBER_END;

	result=param1+1;
	return result;
}

int DummyA::CallR(int param1, int param2)
{
	DBG_CALLMEMBER_RET("DummyA::CallR",false,int,result);
	DBG_PARAM(0,"p1",int,param1);
	DBG_PARAM(1,"p2",int,param2);
	DBG_CALLMEMBER_END;

	result=param1+param2;
	return result;
}

int DummyA::CallR(int param1, int param2, int param3)
{
	DBG_CALLMEMBER_RET("DummyA::CallR",false,int,result);
	DBG_PARAM(0,"p1",int,param1);
	DBG_PARAM(1,"p2",int,param2);
	DBG_PARAM(2,"p3",int,param3);
	DBG_CALLMEMBER_END;

	result=param1+param2+param3;
	return result;
}

void DummyA::CallRec(int param1)
{
	DBG_CALLMEMBER("DummyA::CallRec",false);
	DBG_PARAM(0,"p1",int,param1);
	DBG_CALLMEMBER_END;

	if (param1<=0)
		return;
	CallRec(param1-1);
}

void DummyA::Loop()
{
	DBG_CALLMEMBER("DummyA::Loop",false);
	DBG_CALLMEMBER_END;

	int idx=0;
	int i=0;

	while (idx<10)
	{
		Call();
		Call(idx);
		Call(idx,1);
		Call(idx,1,2);
		CallR();
		CallR(idx);
		CallR(idx,1);
		i=CallR(idx,1,i);
		CallRec(idx);
		idx++;
	}
}
