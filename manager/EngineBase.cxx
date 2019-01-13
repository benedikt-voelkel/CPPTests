#include <iostream>

EngineBase::EngineBase()
{
  RegisterToManager(this);
}

EngineBase::name()
{
  std::cout << "I am an engine" << std::endl;
}
