// **********************************************************************
//
// Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.4.2
//
// <auto-generated>
//
// Generated from file `option_event.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef LOG_ICE_API_EXPORTS
#   define LOG_ICE_API_EXPORTS
#endif
#include <log_ice/ice/option_event.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 304
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 2
#       error Ice patch level mismatch!
#   endif
#endif

static const ::std::string __loggerice__optioneventif__sendevent_name = "sendevent";

ICE_DECLSPEC_EXPORT ::Ice::Object* IceInternal::upCast(::loggerice::optionevent* p) { return p; }
ICE_DECLSPEC_EXPORT ::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::loggerice::optionevent* p) { return p; }

ICE_DECLSPEC_EXPORT ::Ice::Object* IceInternal::upCast(::loggerice::optioneventif* p) { return p; }
ICE_DECLSPEC_EXPORT ::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::loggerice::optioneventif* p) { return p; }

void
loggerice::__read(::IceInternal::BasicStream* __is, ::loggerice::optioneventPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::loggerice::optionevent;
        v->__copyFrom(proxy);
    }
}

void
loggerice::__read(::IceInternal::BasicStream* __is, ::loggerice::optioneventifPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::loggerice::optioneventif;
        v->__copyFrom(proxy);
    }
}
#ifdef __SUNPRO_CC
class ICE_DECLSPEC_EXPORT IceProxy::loggerice::optionevent;
#endif

const ::std::string&
IceProxy::loggerice::optionevent::ice_staticId()
{
    return ::loggerice::optionevent::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::loggerice::optionevent::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::loggerice::optionevent);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::loggerice::optionevent::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::loggerice::optionevent);
}

::IceProxy::Ice::Object*
IceProxy::loggerice::optionevent::__newInstance() const
{
    return new optionevent;
}
#ifdef __SUNPRO_CC
class ICE_DECLSPEC_EXPORT IceProxy::loggerice::optioneventif;
#endif

void
IceProxy::loggerice::optioneventif::sendevent(const ::loggerice::optioneventPtr& theevent, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __delBase = __getDelegate(false);
            ::IceDelegate::loggerice::optioneventif* __del = dynamic_cast< ::IceDelegate::loggerice::optioneventif*>(__delBase.get());
            __del->sendevent(theevent, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::loggerice::optioneventif::begin_sendevent(const ::loggerice::optioneventPtr& theevent, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __loggerice__optioneventif__sendevent_name, __del, __cookie);
    try
    {
        __result->__prepare(__loggerice__optioneventif__sendevent_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__getOs();
        __os->write(::Ice::ObjectPtr(::IceInternal::upCast(theevent.get())));
        __os->writePendingObjects();
        __os->endWriteEncaps();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::loggerice::optioneventif::end_sendevent(const ::Ice::AsyncResultPtr& __result)
{
    __end(__result, __loggerice__optioneventif__sendevent_name);
}

const ::std::string&
IceProxy::loggerice::optioneventif::ice_staticId()
{
    return ::loggerice::optioneventif::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::loggerice::optioneventif::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::loggerice::optioneventif);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::loggerice::optioneventif::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::loggerice::optioneventif);
}

::IceProxy::Ice::Object*
IceProxy::loggerice::optioneventif::__newInstance() const
{
    return new optioneventif;
}

void
IceDelegateM::loggerice::optioneventif::sendevent(const ::loggerice::optioneventPtr& theevent, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __loggerice__optioneventif__sendevent_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(::Ice::ObjectPtr(::IceInternal::upCast(theevent.get())));
        __os->writePendingObjects();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    if(!__og.is()->b.empty())
    {
        try
        {
            if(!__ok)
            {
                try
                {
                    __og.throwUserException();
                }
                catch(const ::Ice::UserException& __ex)
                {
                    ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                    throw __uue;
                }
            }
            __og.is()->skipEmptyEncaps();
        }
        catch(const ::Ice::LocalException& __ex)
        {
            throw ::IceInternal::LocalExceptionWrapper(__ex, false);
        }
    }
}

void
IceDelegateD::loggerice::optioneventif::sendevent(const ::loggerice::optioneventPtr& theevent, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(const ::loggerice::optioneventPtr& theevent, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_theevent(theevent)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::loggerice::optioneventif* servant = dynamic_cast< ::loggerice::optioneventif*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            servant->sendevent(_m_theevent, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        const ::loggerice::optioneventPtr& _m_theevent;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __loggerice__optioneventif__sendevent_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(theevent, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

loggerice::optionevent::optionevent(::Ice::Int __ice_type, ::Ice::Long __ice_ts, ::Ice::Int __ice_srctype, ::Ice::Int __ice_srcid, ::Ice::Int __ice_kind, ::Ice::Long __ice_key, ::Ice::Long __ice_timeMs, ::Ice::Long __ice_threadId, ::Ice::Int __ice_procId, ::Ice::Long __ice_subType, ::Ice::Long __ice_value, const ::std::string& __ice_name, const ::std::string& __ice_strVal) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    event(__ice_type, __ice_ts, __ice_srctype, __ice_srcid, __ice_kind, __ice_key, __ice_timeMs, __ice_threadId, __ice_procId)
#else
    ::loggerice::event(__ice_type, __ice_ts, __ice_srctype, __ice_srcid, __ice_kind, __ice_key, __ice_timeMs, __ice_threadId, __ice_procId)
#endif
,
    subType(__ice_subType),
    value(__ice_value),
    name(__ice_name),
    strVal(__ice_strVal)
{
}

::Ice::ObjectPtr
loggerice::optionevent::ice_clone() const
{
    ::loggerice::optioneventPtr __p = new ::loggerice::optionevent(*this);
    return __p;
}

static const ::std::string __loggerice__optionevent_ids[3] =
{
    "::Ice::Object",
    "::loggerice::event",
    "::loggerice::optionevent"
};

bool
loggerice::optionevent::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__loggerice__optionevent_ids, __loggerice__optionevent_ids + 3, _s);
}

::std::vector< ::std::string>
loggerice::optionevent::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__loggerice__optionevent_ids[0], &__loggerice__optionevent_ids[3]);
}

const ::std::string&
loggerice::optionevent::ice_id(const ::Ice::Current&) const
{
    return __loggerice__optionevent_ids[2];
}

const ::std::string&
loggerice::optionevent::ice_staticId()
{
    return __loggerice__optionevent_ids[2];
}

void
loggerice::optionevent::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->write(subType);
    __os->write(value);
    __os->write(name);
    __os->write(strVal);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    event::__write(__os);
#else
    ::loggerice::event::__write(__os);
#endif
}

void
loggerice::optionevent::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->read(subType);
    __is->read(value);
    __is->read(name);
    __is->read(strVal);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    event::__read(__is, true);
#else
    ::loggerice::event::__read(__is, true);
#endif
}

// COMPILERFIX: Stream API is not supported with VC++ 6
#if !defined(_MSC_VER) || (_MSC_VER >= 1300)
void
loggerice::optionevent::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type loggerice::optionevent was not generated with stream support";
    throw ex;
}

void
loggerice::optionevent::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type loggerice::optionevent was not generated with stream support";
    throw ex;
}
#endif

class __F__loggerice__optionevent : public ::Ice::ObjectFactory
{
public:

    virtual ::Ice::ObjectPtr
    create(const ::std::string& type)
    {
        assert(type == ::loggerice::optionevent::ice_staticId());
        return new ::loggerice::optionevent;
    }

    virtual void
    destroy()
    {
    }
};

static ::Ice::ObjectFactoryPtr __F__loggerice__optionevent_Ptr = new __F__loggerice__optionevent;

const ::Ice::ObjectFactoryPtr&
loggerice::optionevent::ice_factory()
{
    return __F__loggerice__optionevent_Ptr;
}

class __F__loggerice__optionevent__Init
{
public:

    __F__loggerice__optionevent__Init()
    {
        ::IceInternal::factoryTable->addObjectFactory(::loggerice::optionevent::ice_staticId(), ::loggerice::optionevent::ice_factory());
    }

    ~__F__loggerice__optionevent__Init()
    {
        ::IceInternal::factoryTable->removeObjectFactory(::loggerice::optionevent::ice_staticId());
    }
};

static __F__loggerice__optionevent__Init __F__loggerice__optionevent__i;

#ifdef __APPLE__
extern "C" { void __F__loggerice__optionevent__initializer() {} }
#endif

void ICE_DECLSPEC_EXPORT 
loggerice::__patch__optioneventPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::loggerice::optioneventPtr* p = static_cast< ::loggerice::optioneventPtr*>(__addr);
    assert(p);
    *p = ::loggerice::optioneventPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::loggerice::optionevent::ice_staticId(), v->ice_id());
    }
}

::Ice::ObjectPtr
loggerice::optioneventif::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __loggerice__optioneventif_ids[2] =
{
    "::Ice::Object",
    "::loggerice::optioneventif"
};

bool
loggerice::optioneventif::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__loggerice__optioneventif_ids, __loggerice__optioneventif_ids + 2, _s);
}

::std::vector< ::std::string>
loggerice::optioneventif::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__loggerice__optioneventif_ids[0], &__loggerice__optioneventif_ids[2]);
}

const ::std::string&
loggerice::optioneventif::ice_id(const ::Ice::Current&) const
{
    return __loggerice__optioneventif_ids[1];
}

const ::std::string&
loggerice::optioneventif::ice_staticId()
{
    return __loggerice__optioneventif_ids[1];
}

::Ice::DispatchStatus
loggerice::optioneventif::___sendevent(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::loggerice::optioneventPtr theevent;
    __is->read(::loggerice::__patch__optioneventPtr, &theevent);
    __is->readPendingObjects();
    __is->endReadEncaps();
    sendevent(theevent, __current);
    return ::Ice::DispatchOK;
}

static ::std::string __loggerice__optioneventif_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "sendevent"
};

::Ice::DispatchStatus
loggerice::optioneventif::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__loggerice__optioneventif_all, __loggerice__optioneventif_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __loggerice__optioneventif_all)
    {
        case 0:
        {
            return ___ice_id(in, current);
        }
        case 1:
        {
            return ___ice_ids(in, current);
        }
        case 2:
        {
            return ___ice_isA(in, current);
        }
        case 3:
        {
            return ___ice_ping(in, current);
        }
        case 4:
        {
            return ___sendevent(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
loggerice::optioneventif::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
loggerice::optioneventif::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

// COMPILERFIX: Stream API is not supported with VC++ 6
#if !defined(_MSC_VER) || (_MSC_VER >= 1300)
void
loggerice::optioneventif::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type loggerice::optioneventif was not generated with stream support";
    throw ex;
}

void
loggerice::optioneventif::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type loggerice::optioneventif was not generated with stream support";
    throw ex;
}
#endif

void ICE_DECLSPEC_EXPORT 
loggerice::__patch__optioneventifPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::loggerice::optioneventifPtr* p = static_cast< ::loggerice::optioneventifPtr*>(__addr);
    assert(p);
    *p = ::loggerice::optioneventifPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::loggerice::optioneventif::ice_staticId(), v->ice_id());
    }
}
