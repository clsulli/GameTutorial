#pragma once

class SpriteSheet
{
public:
	SpriteSheet();
	SpriteSheet(int _numFrames);
	~SpriteSheet();

	float GetFrameXPos(int _frame);
	float GetFrameYPos(int _frame);

private:
	int numFrames;
};

