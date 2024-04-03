#pragma once
#include "Unique.h"

#include "PlatformFlow/PlatformFlowStateMachine.h"

class PlatformLayer : public Unique::Layer
{
public:
	PlatformLayer();
	~PlatformLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Unique::Timestep ts) override;
	void OnRender(Unique::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Unique::Event& e) override;

	PlatformStateMachine* GetFlowStateMachine() { return m_PlatformStateMachine; }

private:
	bool OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e);
	bool OnWindowResize(Unique::WindowResizeEvent& e);
private:

	PlatformStateMachine* m_PlatformStateMachine;
};
