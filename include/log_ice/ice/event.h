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
// Generated from file `event.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __log_ice_ice_clean_slice___event_h__
#define __log_ice_ice_clean_slice___event_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

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

#ifndef LOG_ICE_API
#   ifdef LOG_ICE_API_EXPORTS
#       define LOG_ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define LOG_ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

namespace loggerice
{

class event;

}

}

namespace loggerice
{

class event;
bool operator==(const event&, const event&);
bool operator<(const event&, const event&);

}

namespace IceInternal
{

LOG_ICE_API ::Ice::Object* upCast(::loggerice::event*);
LOG_ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::loggerice::event*);

}

namespace loggerice
{

typedef ::IceInternal::Handle< ::loggerice::event> eventPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::loggerice::event> eventPrx;

LOG_ICE_API void __read(::IceInternal::BasicStream*, eventPrx&);
LOG_ICE_API void __patch__eventPtr(void*, ::Ice::ObjectPtr&);

}

namespace loggerice
{

}

namespace IceProxy
{

namespace loggerice
{

class event : virtual public ::IceProxy::Ice::Object
{
public:
    
    ::IceInternal::ProxyHandle<event> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<event> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<event*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<event*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    #endif
    }
    
    LOG_ICE_API static const ::std::string& ice_staticId();

private: 

    LOG_ICE_API virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    LOG_ICE_API virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    LOG_ICE_API virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace loggerice
{

class LOG_ICE_API event : virtual public ::IceDelegate::Ice::Object
{
public:
};

}

}

namespace IceDelegateM
{

namespace loggerice
{

class LOG_ICE_API event : virtual public ::IceDelegate::loggerice::event,
                          virtual public ::IceDelegateM::Ice::Object
{
public:
};

}

}

namespace IceDelegateD
{

namespace loggerice
{

class LOG_ICE_API event : virtual public ::IceDelegate::loggerice::event,
                          virtual public ::IceDelegateD::Ice::Object
{
public:
};

}

}

namespace loggerice
{

class LOG_ICE_API event : virtual public ::Ice::Object
{
public:

    typedef eventPrx ProxyType;
    typedef eventPtr PointerType;
    
    event() {}
    event(::Ice::Int, ::Ice::Long, ::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Long, ::Ice::Long, ::Ice::Long, ::Ice::Int);
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();


    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
// COMPILERFIX: Stream API is not supported with VC++ 6
#if !defined(_MSC_VER) || (_MSC_VER >= 1300)
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
#endif

    static const ::Ice::ObjectFactoryPtr& ice_factory();

protected:

    virtual ~event() {}

    friend class event__staticInit;

public:

    ::Ice::Int type;

    ::Ice::Long ts;

    ::Ice::Int srctype;

    ::Ice::Int srcid;

    ::Ice::Int kind;

    ::Ice::Long key;

    ::Ice::Long timeMs;

    ::Ice::Long threadId;

    ::Ice::Int regId;
};

class event__staticInit
{
public:

    ::loggerice::event _init;
};

static event__staticInit _event_init;

inline bool operator==(const event& l, const event& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const event& l, const event& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace loggerice
{

}

#endif
