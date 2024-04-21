#include "uqpch.h"
#include "PlayerData.h"

using Json = nlohmann::json;
namespace Unique 
{

	PlayerData::PlayerData(const std::string& filePath)
	{
		std::ifstream inFile(filePath);
		m_FilePath = filePath;
		if (inFile.is_open()) {
			inFile >> m_Data;
			inFile.close();
		}
		else {
			m_Data = Json({});
		}
	}

	void PlayerData::UpdateScore(const std::string& gameName, int score)
	{
		m_Data[gameName]["Score"] = score;
	}

	void PlayerData::SaveToFile() const
	{
		std::ofstream outFile(m_FilePath);
		if (outFile.is_open()) {
			outFile << m_Data.dump(4); // 美化輸出 JSON
			outFile.close();
		}
	}

	int PlayerData::GetScore(const std::string& gameName) const
	{
		if (m_Data.contains(gameName) && m_Data[gameName].contains("Score")) {
			return m_Data[gameName]["Score"];
		}
		return 0; // 如果沒有分數記錄，返回 0
	}
	void PlayerData::CheckAndReload()
	{
		auto currentWriteTime = std::filesystem::last_write_time(m_FilePath);
		if (currentWriteTime != m_LastWriteTime) {
			std::ifstream inFile(m_FilePath);
			if (inFile.is_open()) {
				inFile >> m_Data;
				inFile.close();
				m_LastWriteTime = currentWriteTime; 
			}
		}
	}
}

