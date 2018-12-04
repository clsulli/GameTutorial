#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "GLFW/glfw3.h"
#include <iostream>

#pragma comment(lib, "opengl32.lib")

using namespace std;

class Engine
{

public:
	// Screen width and height.
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static float GetDT();
	
	// Constructor and Deconstructor.
	Engine();
	~Engine();

	// Engine initialization method, so we don't do all the heavy lifting in the constructor.
	bool Initialize(const char* windowTitle);

	// Update state of the game.
	void Update();
	// Render the state of teh game.
	void BeginRender();
	void EndRender();

private:
	// Pointer to GLFW Window.
	static GLFWwindow* window;
	static float dt;
	float lastTime;
};

#endif
