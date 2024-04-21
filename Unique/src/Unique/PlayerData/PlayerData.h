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
		void SaveToFile() const;
		int GetScore(const std::string& gameName) const;
		void CheckAndReload();
	private:
		std::filesystem::file_time_type m_LastWriteTime;
		Json m_Data;
		std::string m_FilePath;
	};

}




