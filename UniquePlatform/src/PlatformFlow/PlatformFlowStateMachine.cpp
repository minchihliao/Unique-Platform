#include "PlatformFlowStateMachine.h"
#include "PlatformState.h"
void PlatformStateMachine::Init()
{
	SetTransition(PlatformState::Init, new PlatformFlowInitState());
	SetTransition(PlatformState::Menu, new PlatformFlowMenuState());
	SetTransition(PlatformState::End, new PlatformFlowEndState());
	
}

std::string PlatformStateMachine::ConditionToString(PlatformState condition)
{
	switch (condition) {
		case PlatformState::Init: return "Init";
		case PlatformState::Menu: return "Menu";
		case PlatformState::End: return "End";
	default: return "Unknown";
	}
}


