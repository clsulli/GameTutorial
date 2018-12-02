#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow * window, double _x, double _y)
{
	/* GLFW 0,0 is top left of frame.  OpenGL 0,0 is bottom left of frame.
	 So offset the height of the frame by the y position to get the correct
	 mouse coordinates according to OpenGL. */

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}

void Mouse::MouseButtonCallback(GLFWwindow * window, int button, int action, int mods)
{
	if (button < 0)
	{
		return;
	}
	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}
	
	buttons[button] = action != GLFW_RELEASE;
}

double Mouse::GetMouseX()
{
	return x;
}

double Mouse::GetMouseY()
{
	return y;
}

bool Mouse::ButtonDown(int button)
{
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;
}

bool Mouse::ButtonUp(int button)
{
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}

bool Mouse::Button(int button)
{
	return buttons[button];
}
