#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>


class EngineBase
{
  public:
    EngineBase();

    virtual ~EngineBase() = default()

    void name();
};

#endif
