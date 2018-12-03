#ifndef GAME_SPRITESHEET
#define GAME_SPRITESHEET

#include "Frame.h"

class SpriteSheet
{
public:
	SpriteSheet();
	SpriteSheet(int _width, int _height, int _numFrames);
	~SpriteSheet();

	void SetFrame();
	void NextFrame();

	pair <float, float> GetFrameTL();
	pair <float, float> GetFrameTR();
	pair <float, float> GetFrameBR();
	pair <float, float> GetFrameBL();

private:
	Frame frame;
	int currFrame;
	int numFrames;
	int width;
	int height;
	double frameHLvl;
	double frameWLvl;
};

#endif
