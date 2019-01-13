#ifndef MANAGER_H_
#define MANAGER_H_

#include <iostream>
#include "EngineBase.h"


class HooksBase
{
  public:
    HooksBase() = default;

    virtual ~HooksBase() = default;

    virtual void Something() = 0;

};

class ManagerBase
{
  public:
    ManagerBase() : mHooksBase(nullptr), mEngineBase(nullptr)
    {
      mManagerBase = this;
    }

    virtual ~ManagerBase() = default;

    static ManagerBase* Instance()
    {
      return mManagerBase;
    }

    void RegisterHooks(HooksBase* hooks)
    {
      mHooksBase = hooks;
    }


    void RegisterEngine(EngineBase* engine)
    {
      mEngineBase = engine;
    }

    EngineBase* GetEngine() const
    {
      return mEngineBase;
    }

    virtual void HookSomething() = 0;

  private:
    static ManagerBase* mManagerBase;
    /// Pointer to hook base object, e.g. aka TVirtualMCApplication
    HooksBase* mHooksBase;
    /// Pointer to current engine object, e.g. aka TVirtualMC
    EngineBase* mEngineBase;

};

ManagerBase* ManagerBase::mManagerBase = nullptr;


template <class T>
class ManagerSingle : public ManagerBase
{
  public:
    ManagerSingle() : ManagerBase()
    {}

      virtual ~ManagerSingle() = default;

    void RegisterHooks(T* hooks)
    {
      mHooksConcrete = hooks;
      ManagerBase::RegisterHooks(hooks);
    }

    void HookSomething() override final
    {
      std::cout << "Hook for single" << std::endl;
      mHooksConcrete->Something();
    }

  private:
    /// Pointer to concrete hook object
    T* mHooksConcrete;
};

template <class T>
class ManagerMulti : public ManagerBase
{
  public:
    ManagerMulti() : ManagerBase()
    {}

    virtual ~ManagerMulti() = default;

    void RegisterHooks(T* hooks)
    {
      mHooksConcrete = hooks;
      ManagerBase::RegisterHooks(hooks);
    }

    void HookSomething() override final
    {
      std::cout << "Hook for multi\n";
      std::cout << "Do before hook Something()\n";
      mHooksConcrete->Something();
      std::cout << "Do after hook Something()" << std::endl;
    }

  private:
    /// Pointer to concrete hook object
    T* mHooksConcrete;
};


template <typename A>
RegisterToManager(EngineBase* engine)
{

}



#endif
