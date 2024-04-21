#pragma once
#include "Unique.h"


class PlatformLayer;




enum class PlatformState
{
	Init,
	Menu,
	End
};


class PlatformStateMachine : public Unique::StateMachine<PlatformLayer, PlatformState>
{
public:
	explicit PlatformStateMachine(PlatformLayer* owner)
		: Unique::StateMachine<PlatformLayer, PlatformState>(owner) {}
	void Init();
	virtual std::string ConditionToString(PlatformState condition) override;

private:

};

