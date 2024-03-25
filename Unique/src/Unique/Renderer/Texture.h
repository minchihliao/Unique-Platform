#pragma once

#include "Unique/Core.h"
#include "SFML/Graphics/Texture.hpp"
#include <string>

namespace Unique 
{

	class Texture
	{
	public:
		virtual ~Texture() = default;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void* GetData() const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		virtual void* GetData() const = 0;
		static Ref<Texture2D> Create(const std::string& path);
	};

}
