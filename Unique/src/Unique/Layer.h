#pragma once

#include "Unique/Core.h"
#include "Unique/Events/Event.h"


namespace Unique {


	enum LayerType 
	{
		Base,
		ImGui
	};

	class UNIQUE_API Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();
			virtual LayerType GetType() const { return LayerType::Base; }
			virtual void OnAttach() {}
			virtual void OnDetach() {}
			virtual void OnUpdate() {}
			virtual void OnEvent(Event& event) {}


			inline const std::string& GetName() const { return m_DebugName; }
		protected:
			std::string m_DebugName;
	};

}