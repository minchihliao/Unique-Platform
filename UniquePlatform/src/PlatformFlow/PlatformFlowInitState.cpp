#include "PlatformFlowInitState.h"

void PlatformFlowInitState::Enter(PlatformLayer* layer)
{
	UQ_INFO("Platform Init");
	layer->GetFlowStateMachine()->ChangeState(PlatformState::Menu);
}

void PlatformFlowInitState::OnUpdate(PlatformLayer* layer, Unique::Timestep ts)
{

}

void PlatformFlowInitState::OnRender(PlatformLayer* layer)
{
}

void PlatformFlowInitState::OnImGuiRender(PlatformLayer* layer)
{
}

void PlatformFlowInitState::Exit(PlatformLayer* layer)
{
}
