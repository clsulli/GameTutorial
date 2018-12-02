#include "SpriteSheet.h"
#include <math.h>


SpriteSheet::SpriteSheet()
{
}

SpriteSheet::SpriteSheet(int _numFrames)
{
	this->numFrames = _numFrames;
}


SpriteSheet::~SpriteSheet()
{
}

float SpriteSheet::GetFrameXPos(int _frame)
{
	float x = _frame / 3;
	return x;
}

float SpriteSheet::GetFrameYPos(int _frame)
{
	double rows = ceil((double)numFrames / 3.0);
	return _frame/rows;
}
