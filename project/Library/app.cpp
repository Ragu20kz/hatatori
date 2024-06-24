#include "App.h"
#include "sceneManager.h"

bool exitFlag = false;

void AppInit()
{
	SceneManager::Start();
	exitFlag = false;
}

void AppUpdate()
{
	SceneManager::Update();
}

void AppDraw()
{
	SceneManager::Draw();
}

void AppRelease()
{
	SceneManager::Release();
}

void Exit()
{
	exitFlag = true;
}

bool IsExit()
{
	return exitFlag;
}