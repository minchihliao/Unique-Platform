#pragma once
#include "Unique.h"

#include "../PlatformLayer.h"

class PlatformFlowEndState : public Unique::State<PlatformLayer, PlatformState>
{
public:
    PlatformFlowEndState() {}
    void Enter(PlatformLayer* layer) override;
    void OnUpdate(PlatformLayer* layer, Unique::Timestep ts) override;
    void OnRender(PlatformLayer* layer) override;
    void OnImGuiRender(PlatformLayer* layer) override;
    void Exit(PlatformLayer* layer) override;

};

