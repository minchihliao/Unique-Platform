#pragma once
#include "Unique.h"
#include "GameBlock.h"
#include "../PlatformLayer.h"

enum MenuState
{
    GameLibrary,
    Reward
};


struct ButtonInfo {
    std::string label;
    ImVec2 size;
    ImVec2 pos;
    MenuState targetState;
    std::string stateString;

    ButtonInfo(const std::string& label, ImVec2 size, ImVec2 pos, MenuState targetState)
        : label(label), size(size), pos(pos), targetState(targetState)
    {
        switch (targetState)
        {
        case GameLibrary:
            stateString = std::string("Game Library State");
            break;
        case Reward:
            stateString = std::string("Reward State");
            break;
        default:
            break;
        }
    }
};

class PlatformFlowMenuState : public Unique::State<PlatformLayer, PlatformState>
{
public:
    PlatformFlowMenuState()
    :m_CurrentMenuState(MenuState::GameLibrary){}
    void Enter(PlatformLayer* layer) override;
    void OnUpdate(PlatformLayer* layer, Unique::Timestep ts) override;
    void OnRender(PlatformLayer* layer) override;
    void OnImGuiRender(PlatformLayer* layer) override;
    void OnEvent(Event& e) override;
    void Exit(PlatformLayer* layer) override;

private:
    std::vector<GameBlock*> m_GameBlockVector;
    std::vector<ButtonInfo> m_Buttons;
    float m_Time = 0.0f;
    float m_PlayerDataInterval = 0.3f;
    float m_PlayerDataNextCheckTime = m_PlayerDataInterval;
    MenuState m_CurrentMenuState;
};

