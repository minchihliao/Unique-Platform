#pragma once
#include "uqpch.h"

#include "Unique/Core.h"
#include "Unique/Events/Event.h"


namespace Unique
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& titile = "Unique Engine",
						unsigned int width = 1280,
						unsigned int height = 720)
			:Title(titile),Width(width),Height(height)
		{
		}
	};


	class UNQIUE_API Window
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Window attributes
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());

	};














}