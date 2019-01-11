#include <iostream>

#include "Base.h"


class MyClassSingleVirtualCall : public TVirtualMCApplication
{
  public:
    MyClassSingleVirtualCall() : TVirtualMCApplication()
    {
      std::cout << "MyClassSingleVirtualCall construction\n";
    }
    virtual ~MyClassSingleVirtualCall() = default;

    virtual void Something() override
    {
      std::cout << "Something MyClassSingleVirtualCall\n";
    }
};

class MyClassSingleNonVirtualCall : public TVirtualMCSingleApplication<MyClassSingleNonVirtualCall>
{
  public:
    MyClassSingleNonVirtualCall() : TVirtualMCSingleApplication()
    {
      std::cout << "MyClassSingleNonVirtualCall construction\n";
    }
    virtual ~MyClassSingleNonVirtualCall() = default;

    virtual void Something() override
    {
      std::cout << "Something MyClassSingleNonVirtualCall\n";
    }
};


class MyClassMultiVirtualCall : public TVirtualMCMultiApplication<>
{
  public:
    MyClassMultiVirtualCall() : TVirtualMCMultiApplication()
    {
      std::cout << "MyClassMultiVirtualCall construction\n";
    }
    virtual ~MyClassMultiVirtualCall() = default;

    virtual void Something() override
    {
      std::cout << "Something MyClassMultiVirtualCall\n";
    }
};

class MyClassMultiNonVirtualCall : public TVirtualMCMultiApplication<MyClassMultiNonVirtualCall>
{
  public:
    MyClassMultiNonVirtualCall() : TVirtualMCMultiApplication()
    {
      std::cout << "MyClassMultiNonVirtualCall construction\n";
    }
    virtual ~MyClassMultiNonVirtualCall() = default;

    virtual void Something() override
    {
      std::cout << "Something MyClassMultiNonVirtualCall\n";
    }
};



int main(int argc, char* argv[])
{

  MyClassSingleVirtualCall* myClass1 = new MyClassSingleVirtualCall();
  TVirtualMCApplicationBase::Instance()->HookSomething();
  std::cout << "\n\n";

  MyClassSingleNonVirtualCall* myClass2 = new MyClassSingleNonVirtualCall();
  TVirtualMCApplicationBase::Instance()->HookSomething();
  std::cout << "\n\n";

  MyClassMultiVirtualCall* myClass3 = new MyClassMultiVirtualCall();
  TVirtualMCApplicationBase::Instance()->HookSomething();
  std::cout << "\n\n";

  MyClassMultiNonVirtualCall* myClass4 = new MyClassMultiNonVirtualCall();
  TVirtualMCApplicationBase::Instance()->HookSomething();
  std::cout << "\n\n";

  return 0;
}
