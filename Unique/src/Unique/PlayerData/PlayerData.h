#pragma once
#include "uqpch.h"
#include <fstream>
#include "nlohmann/json.hpp"

using Json = nlohmann::json;


namespace Unique 
{
	class PlayerData
	{
	public:
		PlayerData(const std::string& filePath);
		~PlayerData() {}
		void UpdateScore(const std::string& gameName, int score);
		void SaveToFile(const std::string& filePath) const;
		int GetScore(const std::string& gameName) const;

	private:
		Json m_Data;
	};

}




