#include "Frame.h"



Frame::Frame()
{
}

Frame::Frame(pair<float, float> TL, pair<float, float> TR, pair<float, float> BL, pair<float, float> BR)
{
	this->TL = TL;
	this->TR = TR;
	this->BL = BL;
	this->BR = BR;
}

void Frame::SetFirstFrame(int height, int width)
{
	this->xOffset = 1.0f / width;
	this->yOffset = 1.0f / height;

	this->TL.first = 0;
	this->TL.second = xOffset * (float) height;
	
	this->TR.first = xOffset;
	this->TR.second = xOffset * (float)height;

	this->BL.first = 0;
	this->BL.second = xOffset * ((float)height - 1.0f);

	this->BR.first = xOffset;
	this->BR.second = xOffset * ((float)height - 1.0f);

	cout << "SPRITESHEET: " << width << "x" << height << endl;
	cout << "TL: " << TL.first << "-" << TL.second << endl;
	cout << "TR: " << TR.first << "-" << TR.second << endl;
	cout << "BL: " << BL.first << "-" << BL.second << endl;
	cout << "BR: " << BR.first << "-" << BR.second << endl;

}

void Frame::SetFrame(int frameHLvl, int frameWLvl)
{
	for (int i = 1; i < frameHLvl; i++)
	{
		this->FrameDown();
	}
	for (int j = 1;  j < frameWLvl;  j++)
	{
		this->FrameRight();
	}
}

void Frame::FrameRight()
{
	this->TL.first += this->xOffset;
	this->TR.first += this->xOffset;
	this->BL.first += this->xOffset;
	this->BR.first += this->xOffset;
}

void Frame::FrameLeft()
{
	this->TL.first -= this->xOffset;
	this->TR.first -= this->xOffset;
	this->BL.first -= this->xOffset;
	this->BR.first -= this->xOffset;
}

void Frame::FrameDown()
{
	this->TL.second -= this->yOffset;
	this->TR.second -= this->yOffset;
	this->BL.second -= this->yOffset;
	this->BR.second -= this->yOffset;
}

void Frame::FrameUp()
{
	this->TL.second -= this->yOffset;
	this->TR.second -= this->yOffset;
	this->BL.second -= this->yOffset;
	this->BR.second -= this->yOffset;
}


Frame::~Frame()
{
}

pair<float, float> Frame::GetTL()
{
	return this->TL;
}

pair<float, float> Frame::GetTR()
{
	return this->TR;
}

pair<float, float> Frame::GetBR()
{
	return this->BR;
}

pair<float, float> Frame::GetBL()
{
	return this->BL;
}
