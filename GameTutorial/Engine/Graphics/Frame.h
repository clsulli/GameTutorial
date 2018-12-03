#ifndef GAME_SPRITE_FRAME
#define GAME_SPRITE_FRAME

#include <iostream>
#include <utility>
using namespace std;

class Frame
{
public:
	~Frame();
	Frame();
	Frame(pair <float, float> TL, pair <float, float> TR, pair <float, float> BL, pair <float, float> BR);
	
	void SetFirstFrame(int height, int width);
	void SetFrame(int frameHLvl, int frameWLvl);

	void FrameRight();
	void FrameLeft();
	void FrameDown();
	void FrameUp();

	pair <float, float> GetTL();
	pair <float, float> GetTR();
	pair <float, float> GetBR();
	pair <float, float> GetBL();

private:
	pair <float, float> TL;
	pair <float, float> TR;
	pair <float, float> BL;
	pair <float, float> BR;

	float xOffset;
	float yOffset;
};

#endif