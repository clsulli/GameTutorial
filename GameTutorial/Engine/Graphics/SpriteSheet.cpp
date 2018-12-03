#include "SpriteSheet.h"
#include <math.h>

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::SetFrame()
{
	cout << "SETTING FRAME: " << this->currFrame << endl;
	
	this->frameHLvl = ceil((double)this->currFrame / (double)this->height);
	this->frameWLvl =  this->currFrame % this->width;
	if (this->frameWLvl == 0)
	{
		this->frameWLvl = this->frameWLvl + this->width;
	}
	cout << currFrame << " % " << width << " = " << this->currFrame % this->width;

	
	this->frame.SetFirstFrame(this->width, this->height);
	cout << "FHL: " << frameHLvl << "FWL: " << frameWLvl;
	this->frame.SetFrame((int)frameHLvl, (int)frameWLvl);
}

void SpriteSheet::NextFrame()
{
	if (this->currFrame == this->numFrames)
	{
		this->currFrame = 1;
	}
	else
	{
		this->currFrame++;
	}
	cout << this->currFrame << endl;
}

pair<float, float> SpriteSheet::GetFrameTL()
{
	return this->frame.GetTL();;
}

pair<float, float> SpriteSheet::GetFrameTR()
{
	return this->frame.GetTR();
}

pair<float, float> SpriteSheet::GetFrameBR()
{
	return this->frame.GetBR();
}

pair<float, float> SpriteSheet::GetFrameBL()
{
	return this->frame.GetBL();
}

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::SpriteSheet(int _width, int _height, int _numFrames)
{
	this->width = _width;
	this->height = _height;
	this->numFrames = _numFrames;
	this->currFrame = 1;
	this->frame.SetFirstFrame(this->height, this->width);
}
