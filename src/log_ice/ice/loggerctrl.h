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
// Generated from file `loggerctrl.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __log_ice_ice_clean_slice___loggerctrl_h__
#define __log_ice_ice_clean_slice___loggerctrl_h__

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

class loggerctrl;

}

}

namespace loggerice
{

class loggerctrl;
bool operator==(const loggerctrl&, const loggerctrl&);
bool operator<(const loggerctrl&, const loggerctrl&);

}

namespace IceInternal
{

LOG_ICE_API ::Ice::Object* upCast(::loggerice::loggerctrl*);
LOG_ICE_API ::IceProxy::Ice::Object* upCast(::IceProxy::loggerice::loggerctrl*);

}

namespace loggerice
{

typedef ::IceInternal::Handle< ::loggerice::loggerctrl> loggerctrlPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::loggerice::loggerctrl> loggerctrlPrx;

LOG_ICE_API void __read(::IceInternal::BasicStream*, loggerctrlPrx&);
LOG_ICE_API void __patch__loggerctrlPtr(void*, ::Ice::ObjectPtr&);

}

namespace loggerice
{

class Callback_loggerctrl_Register_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_loggerctrl_Register_Base> Callback_loggerctrl_RegisterPtr;

class Callback_loggerctrl_SetName_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_loggerctrl_SetName_Base> Callback_loggerctrl_SetNamePtr;

class Callback_loggerctrl_SetThreadName_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_loggerctrl_SetThreadName_Base> Callback_loggerctrl_SetThreadNamePtr;

}

namespace IceProxy
{

namespace loggerice
{

class loggerctrl : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::Int Register(const ::std::string& name)
    {
        return Register(name, 0);
    }
    ::Ice::Int Register(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return Register(name, &__ctx);
    }

    ::Ice::AsyncResultPtr begin_Register(const ::std::string& name)
    {
        return begin_Register(name, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_Register(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return begin_Register(name, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_Register(const ::std::string& name, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_Register(name, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_Register(const ::std::string& name, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_Register(name, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_Register(const ::std::string& name, const ::loggerice::Callback_loggerctrl_RegisterPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_Register(name, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_Register(const ::std::string& name, const ::Ice::Context& __ctx, const ::loggerice::Callback_loggerctrl_RegisterPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_Register(name, &__ctx, __del, __cookie);
    }

    LOG_ICE_API ::Ice::Int end_Register(const ::Ice::AsyncResultPtr&);
    
private:

    LOG_ICE_API ::Ice::Int Register(const ::std::string&, const ::Ice::Context*);
    LOG_ICE_API ::Ice::AsyncResultPtr begin_Register(const ::std::string&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:

    void SetName(::Ice::Int id, const ::std::string& name)
    {
        SetName(id, name, 0);
    }
    void SetName(::Ice::Int id, const ::std::string& name, const ::Ice::Context& __ctx)
    {
        SetName(id, name, &__ctx);
    }

    ::Ice::AsyncResultPtr begin_SetName(::Ice::Int id, const ::std::string& name)
    {
        return begin_SetName(id, name, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_SetName(::Ice::Int id, const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return begin_SetName(id, name, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_SetName(::Ice::Int id, const ::std::string& name, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetName(id, name, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_SetName(::Ice::Int id, const ::std::string& name, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetName(id, name, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_SetName(::Ice::Int id, const ::std::string& name, const ::loggerice::Callback_loggerctrl_SetNamePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetName(id, name, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_SetName(::Ice::Int id, const ::std::string& name, const ::Ice::Context& __ctx, const ::loggerice::Callback_loggerctrl_SetNamePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetName(id, name, &__ctx, __del, __cookie);
    }

    LOG_ICE_API void end_SetName(const ::Ice::AsyncResultPtr&);
    
private:

    LOG_ICE_API void SetName(::Ice::Int, const ::std::string&, const ::Ice::Context*);
    LOG_ICE_API ::Ice::AsyncResultPtr begin_SetName(::Ice::Int, const ::std::string&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:

    void SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name)
    {
        SetThreadName(regid, threadid, name, 0);
    }
    void SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name, const ::Ice::Context& __ctx)
    {
        SetThreadName(regid, threadid, name, &__ctx);
    }

    ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name)
    {
        return begin_SetThreadName(regid, threadid, name, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return begin_SetThreadName(regid, threadid, name, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetThreadName(regid, threadid, name, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetThreadName(regid, threadid, name, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name, const ::loggerice::Callback_loggerctrl_SetThreadNamePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetThreadName(regid, threadid, name, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int regid, ::Ice::Long threadid, const ::std::string& name, const ::Ice::Context& __ctx, const ::loggerice::Callback_loggerctrl_SetThreadNamePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_SetThreadName(regid, threadid, name, &__ctx, __del, __cookie);
    }

    LOG_ICE_API void end_SetThreadName(const ::Ice::AsyncResultPtr&);
    
private:

    LOG_ICE_API void SetThreadName(::Ice::Int, ::Ice::Long, const ::std::string&, const ::Ice::Context*);
    LOG_ICE_API ::Ice::AsyncResultPtr begin_SetThreadName(::Ice::Int, ::Ice::Long, const ::std::string&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_context(const ::Ice::Context& __context) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_context(__context).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_context(__context).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_adapterId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_adapterId(__id).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_endpoints(__endpoints).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_locatorCacheTimeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_locatorCacheTimeout(__timeout).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_connectionCached(bool __cached) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_connectionCached(__cached).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_endpointSelection(__est).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_secure(bool __secure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_secure(__secure).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_preferSecure(bool __preferSecure) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_preferSecure(__preferSecure).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_router(const ::Ice::RouterPrx& __router) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_router(__router).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_router(__router).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_locator(__locator).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_collocationOptimized(bool __co) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_collocationOptimized(__co).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_twoway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_twoway().get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_twoway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_oneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_oneway().get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_oneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_batchOneway() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_batchOneway().get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_datagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_datagram().get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_datagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_batchDatagram() const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_batchDatagram().get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_compress(bool __compress) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_compress(__compress).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_timeout(int __timeout) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_timeout(__timeout).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    #endif
    }
    
    ::IceInternal::ProxyHandle<loggerctrl> ice_connectionId(const std::string& __id) const
    {
    #if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
        typedef ::IceProxy::Ice::Object _Base;
        return dynamic_cast<loggerctrl*>(_Base::ice_connectionId(__id).get());
    #else
        return dynamic_cast<loggerctrl*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
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

class LOG_ICE_API loggerctrl : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::Int Register(const ::std::string&, const ::Ice::Context*) = 0;

    virtual void SetName(::Ice::Int, const ::std::string&, const ::Ice::Context*) = 0;

    virtual void SetThreadName(::Ice::Int, ::Ice::Long, const ::std::string&, const ::Ice::Context*) = 0;
};

}

}

namespace IceDelegateM
{

namespace loggerice
{

class LOG_ICE_API loggerctrl : virtual public ::IceDelegate::loggerice::loggerctrl,
                               virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::Int Register(const ::std::string&, const ::Ice::Context*);

    virtual void SetName(::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual void SetThreadName(::Ice::Int, ::Ice::Long, const ::std::string&, const ::Ice::Context*);
};

}

}

namespace IceDelegateD
{

namespace loggerice
{

class LOG_ICE_API loggerctrl : virtual public ::IceDelegate::loggerice::loggerctrl,
                               virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::Int Register(const ::std::string&, const ::Ice::Context*);

    virtual void SetName(::Ice::Int, const ::std::string&, const ::Ice::Context*);

    virtual void SetThreadName(::Ice::Int, ::Ice::Long, const ::std::string&, const ::Ice::Context*);
};

}

}

namespace loggerice
{

class LOG_ICE_API loggerctrl : virtual public ::Ice::Object
{
public:

    typedef loggerctrlPrx ProxyType;
    typedef loggerctrlPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::Int Register(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___Register(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void SetName(::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___SetName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void SetThreadName(::Ice::Int, ::Ice::Long, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___SetThreadName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
// COMPILERFIX: Stream API is not supported with VC++ 6
#if !defined(_MSC_VER) || (_MSC_VER >= 1300)
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
#endif
};

inline bool operator==(const loggerctrl& l, const loggerctrl& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const loggerctrl& l, const loggerctrl& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace loggerice
{

template<class T>
class CallbackNC_loggerctrl_Register : public Callback_loggerctrl_Register_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(::Ice::Int);

    CallbackNC_loggerctrl_Register(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::loggerice::loggerctrlPrx __proxy = ::loggerice::loggerctrlPrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_Register(__result);
        }
        catch(::Ice::Exception& ex)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
            __exception(__result, ex);
#else
            ::IceInternal::CallbackNC<T>::__exception(__result, ex);
#endif
            return;
        }
        if(response)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
            (callback.get()->*response)(__ret);
#else
            (::IceInternal::CallbackNC<T>::callback.get()->*response)(__ret);
#endif
        }
    }

    Response response;
};

template<class T> Callback_loggerctrl_RegisterPtr
newCallback_loggerctrl_Register(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_Register<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggerctrl_RegisterPtr
newCallback_loggerctrl_Register(T* instance, void (T::*cb)(::Ice::Int), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_Register<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_loggerctrl_Register : public Callback_loggerctrl_Register_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(::Ice::Int, const CT&);

    Callback_loggerctrl_Register(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), response(cb)
    {
    }

    virtual void __completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::loggerice::loggerctrlPrx __proxy = ::loggerice::loggerctrlPrx::uncheckedCast(__result->getProxy());
        ::Ice::Int __ret;
        try
        {
            __ret = __proxy->end_Register(__result);
        }
        catch(::Ice::Exception& ex)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
            __exception(__result, ex);
#else
            ::IceInternal::Callback<T, CT>::__exception(__result, ex);
#endif
            return;
        }
        if(response)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
            (callback.get()->*response)(__ret, CT::dynamicCast(__result->getCookie()));
#else
            (::IceInternal::Callback<T, CT>::callback.get()->*response)(__ret, CT::dynamicCast(__result->getCookie()));
#endif
        }
    }

    Response response;
};

template<class T, typename CT> Callback_loggerctrl_RegisterPtr
newCallback_loggerctrl_Register(const IceUtil::Handle<T>& instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_Register<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_RegisterPtr
newCallback_loggerctrl_Register(T* instance, void (T::*cb)(::Ice::Int, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_Register<T, CT>(instance, cb, excb, sentcb);
}

template<class T>
class CallbackNC_loggerctrl_SetName : public Callback_loggerctrl_SetName_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_loggerctrl_SetName(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetName<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetName<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetName<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetName<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_loggerctrl_SetName : public Callback_loggerctrl_SetName_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_loggerctrl_SetName(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetName<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetName<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetName<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_SetNamePtr
newCallback_loggerctrl_SetName(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetName<T, CT>(instance, 0, excb, sentcb);
}

template<class T>
class CallbackNC_loggerctrl_SetThreadName : public Callback_loggerctrl_SetThreadName_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_loggerctrl_SetThreadName(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetThreadName<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetThreadName<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetThreadName<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_loggerctrl_SetThreadName<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_loggerctrl_SetThreadName : public Callback_loggerctrl_SetThreadName_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_loggerctrl_SetThreadName(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetThreadName<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetThreadName<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetThreadName<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_loggerctrl_SetThreadNamePtr
newCallback_loggerctrl_SetThreadName(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_loggerctrl_SetThreadName<T, CT>(instance, 0, excb, sentcb);
}

}

#endif
