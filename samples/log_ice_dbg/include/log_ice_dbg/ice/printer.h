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
// Generated from file `printer.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __log_ice_dbg_ice_clean_slice___printer_h__
#define __log_ice_dbg_ice_clean_slice___printer_h__

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
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
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

namespace IceProxy
{

namespace Demo
{

class Printer;
void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::Demo::Printer>&);
::IceProxy::Ice::Object* upCast(::IceProxy::Demo::Printer*);

}

}

namespace Demo
{

class Printer;
bool operator==(const Printer&, const Printer&);
bool operator<(const Printer&, const Printer&);
::Ice::Object* upCast(::Demo::Printer*);
typedef ::IceInternal::Handle< ::Demo::Printer> PrinterPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Demo::Printer> PrinterPrx;
void __patch(PrinterPtr&, const ::Ice::ObjectPtr&);

}

namespace Demo
{

class Callback_Printer_printString_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_Printer_printString_Base> Callback_Printer_printStringPtr;

}

namespace IceProxy
{

namespace Demo
{

class Printer : virtual public ::IceProxy::Ice::Object
{
public:

    void printString(const ::std::string& s)
    {
        printString(s, 0);
    }
    void printString(const ::std::string& s, const ::Ice::Context& __ctx)
    {
        printString(s, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_printString(const ::std::string& s, const ::IceInternal::Function<void ()>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return begin_printString(s, 0, new ::IceInternal::Cpp11FnOnewayCallbackNC(__response, __exception, __sent));
    }
    ::Ice::AsyncResultPtr
    begin_printString(const ::std::string& s, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_printString(s, 0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_printString(const ::std::string& s, const ::Ice::Context& __ctx, const ::IceInternal::Function<void ()>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return begin_printString(s, &__ctx, new ::IceInternal::Cpp11FnOnewayCallbackNC(__response, __exception, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_printString(const ::std::string& s, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_printString(s, &__ctx, ::Ice::newCallback(__completed, __sent));
    }
#endif

    ::Ice::AsyncResultPtr begin_printString(const ::std::string& s)
    {
        return begin_printString(s, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_printString(const ::std::string& s, const ::Ice::Context& __ctx)
    {
        return begin_printString(s, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_printString(const ::std::string& s, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_printString(s, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_printString(const ::std::string& s, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_printString(s, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_printString(const ::std::string& s, const ::Demo::Callback_Printer_printStringPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_printString(s, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_printString(const ::std::string& s, const ::Ice::Context& __ctx, const ::Demo::Callback_Printer_printStringPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_printString(s, &__ctx, __del, __cookie);
    }

    void end_printString(const ::Ice::AsyncResultPtr&);
    
private:

    void printString(const ::std::string&, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_printString(const ::std::string&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<Printer> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_secure(bool __secure) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_twoway() const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_oneway() const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_batchOneway() const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_datagram() const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_batchDatagram() const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_compress(bool __compress) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_timeout(int __timeout) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<Printer> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<Printer*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace IceDelegate
{

namespace Demo
{

class Printer : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void printString(const ::std::string&, const ::Ice::Context*, ::IceInternal::InvocationObserver&) = 0;
};

}

}

namespace IceDelegateM
{

namespace Demo
{

class Printer : virtual public ::IceDelegate::Demo::Printer,
                virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void printString(const ::std::string&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace IceDelegateD
{

namespace Demo
{

class Printer : virtual public ::IceDelegate::Demo::Printer,
                virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void printString(const ::std::string&, const ::Ice::Context*, ::IceInternal::InvocationObserver&);
};

}

}

namespace Demo
{

class Printer : virtual public ::Ice::Object
{
public:

    typedef PrinterPrx ProxyType;
    typedef PrinterPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void printString(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::Ice::DispatchStatus ___printString(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    #ifdef __SUNPRO_CC
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
    #endif
};

inline bool operator==(const Printer& l, const Printer& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const Printer& l, const Printer& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace Demo
{

template<class T>
class CallbackNC_Printer_printString : public Callback_Printer_printString_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_Printer_printString(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

template<class T> Callback_Printer_printStringPtr
newCallback_Printer_printString(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Printer_printString<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Printer_printStringPtr
newCallback_Printer_printString(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Printer_printString<T>(instance, 0, excb, sentcb);
}

template<class T> Callback_Printer_printStringPtr
newCallback_Printer_printString(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Printer_printString<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_Printer_printStringPtr
newCallback_Printer_printString(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Printer_printString<T>(instance, 0, excb, sentcb);
}

template<class T, typename CT>
class Callback_Printer_printString : public Callback_Printer_printString_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_Printer_printString(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

template<class T, typename CT> Callback_Printer_printStringPtr
newCallback_Printer_printString(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Printer_printString<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Printer_printStringPtr
newCallback_Printer_printString(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Printer_printString<T, CT>(instance, 0, excb, sentcb);
}

template<class T, typename CT> Callback_Printer_printStringPtr
newCallback_Printer_printString(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Printer_printString<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_Printer_printStringPtr
newCallback_Printer_printString(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Printer_printString<T, CT>(instance, 0, excb, sentcb);
}

}

#endif
