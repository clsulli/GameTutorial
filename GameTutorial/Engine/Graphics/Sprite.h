#ifndef GAME_SPRITE
#define GAME_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "SpriteSheet.h"
#include <vector>
#include <iostream>
using namespace std;

class Sprite
{
public:
	~Sprite();
	Sprite();
	Sprite(string imagePath, int numFrames);
	Sprite(string imagePath, float _xPos, float _yPos, int _numFrames);
	
	void Update();
	void Render();

	void DetermineState();

	void SpeedTo(float x);
	void SpeedBy(float x);

	void MoveTo(float x, float y);
	void MoveBy(float x, float y);

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(float x, float y);

private:
	Texture texture;
	SpriteSheet spritesheet;

	vector<int> frames;

	float xPos;
	float yPos;

	float speed;
	float rot;

	float xScale;
	float yScale;

	int numFrames;
	int currFrame;
};

#endif

