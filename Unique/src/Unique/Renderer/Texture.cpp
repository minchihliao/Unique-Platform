#include "uqpch.h"
#include "Unique/Renderer/Texture.h"
#include "Unique/Core.h"
#include "Unique/Platform/SFML/SFMLTexture2D.h"

namespace Unique 
{

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		return  CreateRef<SFMLTexture>(path);
	}

}