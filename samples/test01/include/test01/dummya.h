#ifndef __DUMMYA_H__
#define __DUMMYA_H__

#include <ostream>

class DummyObj
{
public:
    DummyObj();

    int m_a;
    int m_b;
};

std::ostream &operator<< (std::ostream &os,DummyObj &p);

class DummyA
{
public:
    DummyA();
    virtual ~DummyA();

    void Call();
    void Call(int param1);
    void Call(int param1, int param2);
    void Call(int param1, int param2, int param3);
    void Call(int param1, DummyObj &obj_1);

    int CallR();
    int CallR(int param1);
    int CallR(int param1, int param2);
    int CallR(int param1, int param2, int param3);
    int CallR(int param1, DummyObj &obj_1);

    void CallRec(int param1, DummyObj &obj_1);
    
    void Loop();

    DummyObj m_obj_1;
    DummyObj m_obj_2;
};

#endif

