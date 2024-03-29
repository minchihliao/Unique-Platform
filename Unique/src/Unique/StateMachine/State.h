#pragma once
#include "uqpch.h"
#include "Unique/Events/Event.h"


namespace Unique 
{

    template<typename T, typename Condition>
    class State {
    public:
        virtual ~State() = default;
        virtual void Enter(T*) {}
        virtual void Exit(T*) {}
        virtual void OnEvent(Event& e) {}
        virtual void OnUpdate(T*, Timestep ts) {}
        virtual void OnRender(T*) {}
        virtual void OnImGuiRender(T*) {}
    };


}