#pragma once
#include "Unique/Layer.h"
#include "Unique/Platform/Windows/SFMLWindow.h"

#include "imgui.h"
#include "imgui-SFML.h"

namespace Unique {

	class UNIQUE_API ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();
			virtual void OnAttach() override;
			virtual void OnDetach() override;
			void Begin();
			void End();
			virtual void OnImGuiRender() override;
			void OnEvent(Event& event);
		private:
			float m_Time = 0.0f;
			sf::Clock deltaClock;
	};

}