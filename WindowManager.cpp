#include "WindowManager.h"

WindowManager::WindowManager():m_pMainWindow(NULL)
{

}

WindowManager::~WindowManager()
{

}

WindowManager *WindowManager::Instance()
{
    static WindowManager windowManager;

    return &windowManager;
}

void WindowManager::SetMainWindow(MainWindow *pMainWindow)
{
    m_pMainWindow = pMainWindow;
}

MainWindow *WindowManager::GetMainWindow()
{
    return m_pMainWindow;
}
