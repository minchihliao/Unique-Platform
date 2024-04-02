#pragma once
#include "Unique.h"


class Block
{
public:
	Block(const std::string& name = "Layer") 
		:m_Name(name)
	{
	}
	virtual ~Block() = default;
	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void OnUpdate(Unique::Timestep ts) {}
	virtual void OnRender(Unique::Timestep ts) {}
	virtual void OnImGuiRender() {}
	virtual void OnEvent(Unique::Event& event) {}

	inline const std::string& GetName() const { return m_Name; }
protected:
	std::string m_Name;
};

