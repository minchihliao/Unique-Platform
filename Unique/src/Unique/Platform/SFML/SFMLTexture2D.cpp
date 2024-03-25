#include "uqpch.h"
#include "SFMLTexture2D.h"

namespace Unique 
{
	SFMLTexture::SFMLTexture(const std::string& path)
	{
		m_Texture = new sf::Texture();
		bool result = m_Texture->loadFromFile(path);
		if (!result)
			UQ_CORE_ASSERT(false, "Can't Load Texture File!");
		auto [width, height] = m_Texture->getSize();
		m_Path = path;
		m_Width = width;
		m_Height = height;
	}

	SFMLTexture::~SFMLTexture()
	{
		m_Texture->~Texture();
	}

}






