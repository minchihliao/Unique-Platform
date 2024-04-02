#pragma once
#include "Unique.h"
#include "GameBlock.h"

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
private:
	bool OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e);
	bool OnWindowResize(Unique::WindowResizeEvent& e);
private:
	std::vector<GameBlock*> m_GameBlockVector;

};
