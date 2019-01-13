#include <iostream>

#include "Manager.h"


class MyHooks : public HooksBase
{
  public:
    MyHooks() : HooksBase()
    {
      std::cout << "MyHooks construction\n";
    }
    virtual ~MyHooks() = default;

    virtual void Something() override
    {
      std::cout << "Something MyHooks\n";
    }
};




int main(int argc, char* argv[])
{

  MyHooks* hooks = new MyHooks();
  ManagerSingle<MyHooks>* mgrSingle = new ManagerSingle<MyHooks>();
  mgrSingle->RegisterHooks(hooks);

  ManagerMulti<MyHooks>* mgrMulti = new ManagerMulti<MyHooks>();
  mgrMulti->RegisterHooks(hooks);

  ManagerBase* mgrSingleBase = mgrSingle;
  ManagerBase* mgrMultiBase = mgrMulti;

  mgrSingleBase->HookSomething();
  mgrMultiBase->HookSomething();

  return 0;
}
