#include <iostream>

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

using namespace std;

int main() {
	cout << "GAME_TUTORIAL v0.0.1" << endl;
	
	Engine engine;
	engine.Initialize("Game Tutorial");

	Sprite testSprite = Sprite("Assets/Art/spritesheet.png", 3, 3, 8);
	testSprite.SetScale(0.025f);
	int x = 0;
	while (true)
	{
		x++;
		engine.Update();
		

		if (Keyboard::Key(GLFW_KEY_G))
		{
			testSprite.SpriteNextFrame();
		}

		if (Keyboard::Key(GLFW_KEY_H))
		{
		
		}

		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			testSprite.RotateBy(100);
		}

		if (Keyboard::Key(GLFW_KEY_W))
		{
			testSprite.MoveUp();
		}

		if (Keyboard::Key(GLFW_KEY_S))
		{
			testSprite.MoveDown();
		}

		if (Keyboard::Key(GLFW_KEY_A))
		{
			testSprite.MoveLeft();
		}

		if (Keyboard::Key(GLFW_KEY_D))
		{
			testSprite.MoveRight();
		}

		engine.BeginRender();
		testSprite.Render();
		if (x % 7 == 0)
		{
			testSprite.SpriteNextFrame();
		}
		engine.EndRender();
	}


	return 0;
}