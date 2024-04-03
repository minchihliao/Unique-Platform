#pragma once
#include "Unique.h"
#include "Block.h"
using namespace Unique;
class GameBlock : public Block
{
public:
	GameBlock(std::string name,sf::Vector2f pos);
	virtual ~GameBlock() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(Unique::Timestep ts) override;
	virtual void OnRender() override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Unique::Event& event) override;

private:
	sf::Vector2f m_ButtonPos;
	std::string getCurrentFilePath();
	void execute();

};


