#include "GameBlock.h"
using namespace Unique;
#include <windows.h>
#include <iostream>

GameBlock::GameBlock(std::string name, sf::Vector2f pos)
	:Block(name), m_ButtonPos(pos)
{
}

void GameBlock::OnAttach()
{
}

void GameBlock::OnDetach()
{
}

void GameBlock::OnUpdate(Unique::Timestep ts)
{
}

void GameBlock::OnRender()
{
}

void GameBlock::OnImGuiRender()
{
	auto window = static_cast<sf::RenderWindow*>(Unique::Application::Get().GetWindow().GetNativeWindow());
	ImVec2 windowCenterPos = window->getSize();
	windowCenterPos.x /= 2.f;
	windowCenterPos.y /= 2.f;

	ImVec2 buttonPos = windowCenterPos;
	buttonPos.x += m_ButtonPos.x;
	buttonPos.y += m_ButtonPos.y;
	ImGui::SetCursorPos(buttonPos);

	char* charArray = new char[m_Name.length() + 1];
	strcpy(charArray, m_Name.c_str());
	
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
	if (ImGui::Button(charArray, ImVec2(320	, 180))) {
		execute();
	}
	ImGui::PopFont();
}

void GameBlock::OnEvent(Unique::Event& event)
{
}

std::string GameBlock::getCurrentFilePath()
{
    char path[MAX_PATH];
    std::string gameExePath;

    // 獲取當前執行文件的完整路徑
    if (GetModuleFileNameA(NULL, path, MAX_PATH) != 0) {
        // 將路徑轉換為std::string，方便操作
        std::string fullPath(path);

        // 查找最後一個反斜杠的位置，這樣我們就可以獲取目錄
        size_t pos = fullPath.find_last_of("\\/");
        if (pos != std::string::npos) {
            // 從目錄路徑構建遊戲的.exe路徑
            std::string dirPath = fullPath.substr(0, pos);

            pos = dirPath.find_last_of("\\/");
            if (pos != std::string::npos) {
                gameExePath = dirPath.substr(0, pos + 1) + m_Name + "\\" + m_Name + ".exe";
                return gameExePath;
            }
        }
    }
    return "";
}

void GameBlock::execute()
{
    std::string path = getCurrentFilePath();
    UQ_INFO(path);

    if (path.empty()) {
        printf("Failed to get the game executable path.\n");
        return;
    }

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));


    LPCSTR lpGamePath = path.c_str();

    if (!CreateProcessA(lpGamePath, 
        NULL,      
        NULL,      
        NULL,       
        FALSE,     
        0,          
        NULL,      
        NULL,       
        &si,       
        &pi)        
        ) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }

    // 等待直到子進程退出。
    WaitForSingleObject(pi.hProcess, INFINITE);

    // 關閉進程和線程句柄
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}


