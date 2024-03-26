#pragma once
#include "uqpch.h"


namespace Unique 
{

    template<typename T, typename Condition>
    class State {
    public:
        virtual ~State() = default;
        virtual void Enter(T*) {}
        virtual void Exit(T*) {}
        virtual void Update(T*) {}
    };


}