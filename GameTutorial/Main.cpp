#include <iostream>

#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "FlappyBruh/Flapper.h"

using namespace std;

int main() {
	cout << "GAME_TUTORIAL v0.0.1" << endl;
	
	Engine engine;
	engine.Initialize("Game Tutorial");

	Sprite testSprite = Sprite("Assets/Art/spritesheet.png", Vector3(100, 0, 0), 3, 3, 8);
	testSprite.SetScale(0.025f);

	Flapper player(testSprite);
	int x = 0;
	while (true)
	{
		x++;
		engine.Update();
		

		if (Keyboard::Key(GLFW_KEY_G))
		{
			player.GetSprite().RotateBy(100);
		}

		if (Keyboard::Key(GLFW_KEY_H))
		{
			player.GetSprite().RotateBy(-100);
		}

		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			player.GetSprite().RotateBy(100);
		}

		if (Keyboard::Key(GLFW_KEY_W))
		{
			player.GetRB().AddForce(Vector3(0, 0.5, 0));
		}

		if (Keyboard::Key(GLFW_KEY_S))
		{
			player.GetRB().AddForce(Vector3(0, -0.5, 0));
		}

		if (Keyboard::Key(GLFW_KEY_A))
		{
			player.GetRB().AddForce(Vector3(-0.5, 0, 0));
		}

		if (Keyboard::Key(GLFW_KEY_D))
		{
			player.GetRB().AddForce(Vector3(0.5, 0, 0));
		}

		engine.BeginRender();
		player.Update();
		player.Render();
		if (x % 7 == 0)
		{
			player.GetSprite().SpriteNextFrame();
		}
		engine.EndRender();
	}


	return 0;
}