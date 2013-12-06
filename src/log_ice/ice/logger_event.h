// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `logger_event.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __log_ice_ice_clean_slice___logger_event_h__
#define __log_ice_ice_clean_slice___logger_event_h__

#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include <log_ice/ice/event.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
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

class loggerevent;
LOG_ICE_API void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::loggerice::loggerevent>&);
LOG_ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::loggerice::loggerevent*);

class loggereventif;
LOG_ICE_API void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::loggerice::loggereventif>&);
LOG_ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::loggerice::loggereventif*);

}

}

namespace loggerice
{

class loggerevent;
bool operator==(const loggerevent&, const loggerevent&);
bool operator<(const loggerevent&, const loggerevent&);
LOG_ICE_API ::Ice::Object* upCast(::loggerice::loggerevent*);
typedef ::IceInternal::Handle< ::loggerice::loggerevent> loggereventPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::loggerice::loggerevent> loggereventPrx;
LOG_ICE_API void __patch(loggereventPtr&, const ::Ice::ObjectPtr&);

class loggereventif;
bool operator==(const loggereventif&, const loggereventif&);
bool operator<(const loggereventif&, const loggereventif&);
LOG_ICE_API ::Ice::Object* upCast(::loggerice::loggereventif*);
typedef ::IceInternal::Handle< ::loggerice::loggereventif> loggereventifPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::loggerice::loggereventif> loggereventifPrx;
LOG_ICE_API void __patch(loggereventifPtr&, const ::Ice::ObjectPtr&);

}

namespace loggerice
{

class Callback_loggereventif_sendevent_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_loggereventif_sendevent_Base> Callback_loggereventif_sendeventPtr;

}

namespace IceProxy
{

namespace loggerice
{

class loggerevent : virtual public ::IceProxy::loggerice::event
{
public:
    
    ::IceInternal::ProxyHandle<loggerevent> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_secure(bool __secure) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_twoway() const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_oneway() const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_batchOneway() const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_datagram() const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_batchDatagram() const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_compress(bool __compress) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_timeout(int __timeout) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<loggerevent> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<loggerevent*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    LOG_ICE_API static const ::std::string& ice_staticId();

private: 

    LOG_ICE_API virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    LOG_ICE_API virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    LOG_ICE_API virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class loggereventif : virtual public ::IceProxy::Ice::Object
{
public:

    void sendevent(const ::loggerice::loggereventPtr& theevent)
    {
        sendevent(theevent, 0);
    }
    void sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::Context& __ctx)
    {
        sendevent(theevent, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::IceInternal::Function<void ()>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return begin_sendevent(theevent, 0, new ::IceInternal::Cpp11FnOnewayCallbackNC(__response, __exception, __sent));
    }
    ::Ice::AsyncResultPtr
    begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_sendevent(theevent, 0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::Context& __ctx, const ::IceInternal::Function<void ()>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return begin_sendevent(theevent, &__ctx, new ::IceInternal::Cpp11FnOnewayCallbackNC(__response, __exception, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_sendevent(theevent, &__ctx, ::Ice::newCallback(__completed, __sent));
    }
#endif

    ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr& theevent)
    {
        return begin_sendevent(theevent, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::Context& __ctx)
    {
        return begin_sendevent(theevent, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_sendevent(theevent, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_sendevent(theevent, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::loggerice::Callback_loggereventif_sendeventPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_sendevent(theevent, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr& theevent, const ::Ice::Context& __ctx, const ::loggerice::Callback_loggereventif_sendeventPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_sendevent(theevent, &__ctx, __del, __cookie);
    }

    LOG_ICE_API void end_sendevent(const ::Ice::AsyncResultPtr&);
    
private:

    LOG_ICE_API void sendevent(const ::loggerice::loggereventPtr&, const ::Ice::Context*);
    LOG_ICE_API ::Ice::AsyncResultPtr begin_sendevent(const ::loggerice::loggereventPtr&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<loggereventif> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_secure(bool __secure) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_twoway() const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_oneway() const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_batchOneway() const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_datagram() const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_batchDatagram() const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_compress(bool __compress) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_timeout(int __timeout) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<loggereventif> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<loggereventif*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
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

class LOG_ICE_API loggerevent : virtual public ::IceDelegate::loggerice::event
{
public:
};

class LOG_ICE_API loggereventif : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void sendevent(const ::loggerice::loggereventPtr&, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace loggerice
{

class LOG_ICE_API loggerevent : virtual public ::IceDelegate::loggerice::loggerevent,
                                virtual public ::IceDelegateM::loggerice::event
{
public:
};

class LOG_ICE_API loggereventif : virtual public ::IceDelegate::loggerice::loggereventif,
                                  virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void sendevent(const ::loggerice::loggereventPtr&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace loggerice
{

class LOG_ICE_API loggerevent : virtual public ::IceDelegate::loggerice::loggerevent,
                                virtual public ::IceDelegateD::loggerice::event
{
public:
};

class LOG_ICE_API loggereventif : virtual public ::IceDelegate::loggerice::loggereventif,
                                  virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void sendevent(const ::loggerice::loggereventPtr&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace loggerice
{

class LOG_ICE_API loggerevent : public ::loggerice::event
{
public:

    typedef loggereventPrx ProxyType;
    typedef loggereventPtr PointerType;

    loggerevent()
    {
    }

    loggerevent(::Ice::Int __ice_type, ::Ice::Long __ice_ts, ::Ice::Int __ice_srctype, ::Ice::Int __ice_srcid, ::Ice::Int __ice_kind, ::Ice::Long __ice_key, ::Ice::Long __ice_timeMs, ::Ice::Long __ice_threadId, ::Ice::Int __ice_regId, ::Ice::Long __ice_subType, ::Ice::Long __ice_value, const ::std::string& __ice_name) :
        ::loggerice::event(__ice_type, __ice_ts, __ice_srctype, __ice_srcid, __ice_kind, __ice_key, __ice_timeMs, __ice_threadId, __ice_regId)
        ,
        subType(__ice_subType),
        value(__ice_value),
        name(__ice_name)
    {
    }

    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();


    static const ::Ice::ObjectFactoryPtr& ice_factory();

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::loggerice::event::__writeImpl;
    using ::loggerice::event::__readImpl;
    #endif

public:

    ::Ice::Long subType;

    ::Ice::Long value;

    ::std::string name;

protected:

    virtual ~loggerevent() {}

    friend class loggerevent__staticInit;
};

class loggerevent__staticInit
{
public:

    ::loggerice::loggerevent _init;
};

static loggerevent__staticInit _loggerevent_init;

inline bool operator==(const loggerevent& l, const loggerevent& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const loggerevent& l, const loggerevent& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

class LOG_ICE_API loggereventif : virtual public ::Ice::Object
{
public:

    typedef loggereventifPrx ProxyType;
    typedef loggereventifPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void sendevent(const ::loggerice::loggereventPtr&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___sendevent(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const loggereventif& l, const loggereventif& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const loggereventif& l, const loggereventif& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace loggerice
{

template<class T>
class CallbackNC_loggereventif_sendevent : public Callback_loggereventif_sendevent_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_loggereventif_sendevent(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggereventif_sendevent<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggereventif_sendevent<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggereventif_sendevent<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggereventif_sendevent<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_loggereventif_sendevent : public Callback_loggereventif_sendevent_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_loggereventif_sendevent(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggereventif_sendevent<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggereventif_sendevent<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggereventif_sendevent<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggereventif_sendeventPtr
newCallback_loggereventif_sendevent(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggereventif_sendevent<T, CT>(instance, 0, excb, sentcb);
}

}

#endif
