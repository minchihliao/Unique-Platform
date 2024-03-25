#pragma once
#include "Unique/Renderer/Texture.h"

namespace Unique 
{
	class SFMLTexture : public Texture2D
	{
	public:
		SFMLTexture(const std::string& path);
		virtual ~SFMLTexture();

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }
		virtual void* GetData() const override { return m_Texture; }

	private:
		std::string m_Path;
		uint32_t m_Width, m_Height;
		sf::Texture* m_Texture;
	};

}