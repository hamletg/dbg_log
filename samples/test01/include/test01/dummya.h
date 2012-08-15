#ifndef __DUMMYA_H__
#define __DUMMYA_H__

class DummyA
{
public:
	DummyA();
	virtual ~DummyA();

	void Call();
	void Call(int param1);
	void Call(int param1, int param2);
	void Call(int param1, int param2, int param3);

	int CallR();
	int CallR(int param1);
	int CallR(int param1, int param2);
	int CallR(int param1, int param2, int param3);

	void CallRec(int param1);
	
	void Loop();

};

#endif

