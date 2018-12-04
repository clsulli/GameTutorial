#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "SpriteSheet.h"
#include "../Math/Vector3.h"
#include <vector>
#include <iostream>
using namespace std;

class Sprite
{
public:
	~Sprite();
	Sprite();
	Sprite(string imagePath, int _spritesheetWidth, int _spritesheetHeight, int _spritesheetFrames);
	Sprite(string imagePath, Vector3 _pos, int _spritesheetWidth, int _spritesheetHeight, int _spritesheetFrames);
	
	void Update();
	void Render();

	void SpriteNextFrame();
	void DetermineState();
	
	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(Vector3 v);

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

private:
	Texture texture;
	SpriteSheet spritesheet;

	vector<int> frames;

	Vector3 pos;
	Vector3 scale;
	Vector3 size;

	float speed;
	float rot;
};

#endif

