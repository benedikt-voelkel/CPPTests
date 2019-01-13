#ifndef BASE_H_
#define BASE_H_

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

template <class T=TVirtualMCApplicationBase>
class TVirtualMCMultiApplication : public TVirtualMCApplicationBase
{
  public:
    TVirtualMCMultiApplication() : TVirtualMCApplicationBase() {}
    virtual ~TVirtualMCMultiApplication() = default;

    virtual void HookSomething() override
    {
      std::cout << "Before something is done\n";
      static_cast<T*>(this)->Something();
      std::cout << "After something was done" << std::endl;
    }
};

template <>
TVirtualMCMultiApplication<TVirtualMCApplicationBase>::TVirtualMCMultiApplication() : TVirtualMCApplicationBase()
{
  std::cout << "Warning: Hooks will be called entirely virtual." << std::endl;
}

template<class T=TVirtualMCApplicationBase>
class TVirtualMCSingleApplication : public TVirtualMCApplicationBase
{
  public:
    TVirtualMCSingleApplication() : TVirtualMCApplicationBase() {}
    virtual ~TVirtualMCSingleApplication() = default;

    virtual void HookSomething() override
    {
      static_cast<T*>(this)->Something();
    }
};

template <>
TVirtualMCSingleApplication<TVirtualMCApplicationBase>::TVirtualMCSingleApplication() : TVirtualMCApplicationBase()
{
  std::cout << "Warning: Hooks will be called entirely virtual." << std::endl;
}

typedef TVirtualMCSingleApplication<> TVirtualMCApplication;

#endif
