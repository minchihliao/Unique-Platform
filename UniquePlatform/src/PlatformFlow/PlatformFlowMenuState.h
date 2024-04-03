#pragma once
#include "Unique.h"
#include "GameBlock.h"
#include "../PlatformLayer.h"

class PlatformFlowMenuState : public Unique::State<PlatformLayer, PlatformState>
{
public:
    PlatformFlowMenuState() {}
    void Enter(PlatformLayer* layer) override;
    void OnUpdate(PlatformLayer* layer, Unique::Timestep ts) override;
    void OnRender(PlatformLayer* layer) override;
    void OnImGuiRender(PlatformLayer* layer) override;
    void OnEvent(Event& e) override;
    void Exit(PlatformLayer* layer) override;

private:
    std::vector<GameBlock*> m_GameBlockVector;
};

