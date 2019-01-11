#ifndef BASE_H_
#define BASE_H_

class Default;

class TVirtualMCApplicationBase
{
  public:
    TVirtualMCApplicationBase()
    {
      mBasePtr = this;
    }

    virtual ~TVirtualMCApplicationBase() = default;

    virtual void HookSomething() = 0;

    virtual void Something() = 0;

    static TVirtualMCApplicationBase* Instance()
    {
      return mBasePtr;
    }

  private:
    static TVirtualMCApplicationBase* mBasePtr;

};

TVirtualMCApplicationBase* TVirtualMCApplicationBase::mBasePtr = nullptr;

template <class T=Default>
class TVirtualMCMultiApplication : public TVirtualMCApplicationBase
{
public:
  TVirtualMCMultiApplication() : TVirtualMCApplicationBase() {}
  virtual ~TVirtualMCMultiApplication() = default;

  virtual void HookSomething() override
  {
    std::cout << "Hook non-virtual\n";
    std::cout << "Before something is done\n";
    static_cast<T*>(this)->Something();
    std::cout << "After something was done" << std::endl;
  }
};

template<class T=Default>
class TVirtualMCSingleApplication : public TVirtualMCApplicationBase
{
  public:
    TVirtualMCSingleApplication() : TVirtualMCApplicationBase() {}
    virtual ~TVirtualMCSingleApplication() = default;

    virtual void HookSomething() override
    {
      std::cout << "Hook non-virtual\n";
      static_cast<T*>(this)->Something();
    }
};

template<>
class TVirtualMCSingleApplication<Default> : public TVirtualMCApplicationBase
{
  public:
    TVirtualMCSingleApplication() : TVirtualMCApplicationBase() {}
    virtual ~TVirtualMCSingleApplication() = default;

    virtual void HookSomething() override
    {
      std::cout << "Hook virtual\n";
      Something();
    }
};

template<>
class TVirtualMCMultiApplication<Default> : public TVirtualMCApplicationBase
{
  public:
    TVirtualMCMultiApplication() : TVirtualMCApplicationBase() {}
    virtual ~TVirtualMCMultiApplication() = default;

    virtual void HookSomething() override
    {
      std::cout << "Hook virtual\n";
      std::cout << "Before something is done\n";
      Something();
      std::cout << "After something was done" << std::endl;
    }
};

typedef TVirtualMCSingleApplication<> TVirtualMCApplication;

#endif
