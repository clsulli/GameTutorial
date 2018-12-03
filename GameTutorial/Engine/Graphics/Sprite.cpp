#include "Sprite.h"
#include "../Engine.h"


string animationSequence[] = { "Art/Assets/frame-1.png", "Art/Assets/frame-2.png" , "Art/Assets/frame-3.png" , "Art/Assets/frame-4.png" , "Art/Assets/frame-5.png" , "Art/Assets/frame-6.png"  ,"Art/Assets/frame-7.png", "Art/Assets/frame-8.png" };


Sprite::~Sprite()
{
}

Sprite::Sprite()
{
	this->texture = Texture();
	this->xPos = 0;
	this->yPos = 0;
	this->rot = 0;
	this->speed = 250;
}

Sprite::Sprite(string imagePath, int _spritesheetHeight, int _spritesheetWidth, int _spritesheetFrames)
{
	this->texture = Texture(imagePath);
	this->spritesheet = SpriteSheet(_spritesheetWidth, _spritesheetHeight, _spritesheetFrames);
	this->xPos = 0;
	this->yPos = 0;
	this->rot = 0;
	this->speed = 250;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos, int _spritesheetHeight, int _spritesheetWidth, int _spritesheetFrames)
{
	this->texture = Texture(imagePath);
	this->spritesheet = SpriteSheet(_spritesheetWidth, _spritesheetHeight, _spritesheetFrames);
	this->xPos = _xPos;
	this->yPos = _yPos;
	this->rot = 0;
	this->speed = 250;
}


void Sprite::Update()
{
	
}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->texture.GetID());
	glLoadIdentity();

	// TRANSLATE -> ROTATE -> SCALE
	glTranslatef(this->xPos, this->yPos, 0);
	glRotatef(this->rot, 0, 0, 1);
	glScalef(this->xScale, this->yScale, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	this->DetermineState();
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void Sprite::SpriteNextFrame()
{
	this->spritesheet.NextFrame();
	this->spritesheet.SetFrame();
}

void Sprite::DetermineState()
{
	pair <float, float> TL = this->spritesheet.GetFrameTL();
	pair <float, float> BL = this->spritesheet.GetFrameBL();
	pair <float, float> TR = this->spritesheet.GetFrameTR();
	pair <float, float> BR = this->spritesheet.GetFrameBR();

	glTexCoord2f(BL.first, BL.second); glVertex2f(0, 0);
	/*cout << "BL: " << BL.first << " " << BL.second << endl;*/
	glTexCoord2f(BR.first, BR.second); glVertex2f(this->texture.GetWidth(), 0);
	/*cout << "BR: " << BR.first << " " << BR.second << endl;*/
	glTexCoord2f(TR.first, TR.second); glVertex2f(this->texture.GetWidth(), this->texture.GetHeight());
	/*cout << "TR: " << TR.first << " " << TR.second << endl;*/
	glTexCoord2f(TL.first,  TL.second);	glVertex2f(0, this->texture.GetHeight());
	/*cout << "TL: " << TL.first << " " << TL.second << endl;*/

}


void Sprite::SpeedTo(float x)
{
	this->speed = x;
}

void Sprite::SpeedBy(float x)
{
	this->speed += x;
}

void Sprite::MoveTo(float x, float y)
{
	this->xPos = x;
	this->yPos = y;
}

void Sprite::MoveBy(float x, float y)
{
	this->xPos += (x * Engine::GetDT());
	this->yPos += (y * Engine::GetDT());
}

void Sprite::MoveLeft()
{
	this->xPos -= (speed * Engine::GetDT());
}

void Sprite::MoveRight()
{
	this->xPos += (speed * Engine::GetDT());
}

void Sprite::MoveUp()
{
	this->yPos += (speed * Engine::GetDT());
}

void Sprite::MoveDown()
{
	this->yPos -= (speed * Engine::GetDT());
}

void Sprite::RotateTo(float x)
{
	this->rot = x;
}
void Sprite::RotateBy(float x)
{
	this->rot += (x * Engine::GetDT());
}

void Sprite::SetScale(float x)
{
	this->xScale = x;
	this->yScale = x;
}

void Sprite::SetScale(float x, float y)
{
	this->xScale = x;
	this->yScale = y;
}