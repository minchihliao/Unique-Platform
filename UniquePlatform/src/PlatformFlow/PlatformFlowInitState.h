#pragma once
#include "Unique.h"

#include "../PlatformLayer.h"

class PlatformFlowInitState : public Unique::State<PlatformLayer, PlatformState>
{
public:
    PlatformFlowInitState() {}
    void Enter(PlatformLayer* layer) override;
    void OnUpdate(PlatformLayer* layer, Unique::Timestep ts) override;
    void OnRender(PlatformLayer* layer) override;
    void OnImGuiRender(PlatformLayer* layer) override;
    void Exit(PlatformLayer* layer) override;

private:
    bool m_Start = false;
    float m_Time = 0.0f;
    float m_WaitingTime = 2.f;
};

