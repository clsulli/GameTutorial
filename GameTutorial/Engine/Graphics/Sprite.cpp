#include "Sprite.h"
#include "../Engine.h"

string animationSequence[] = { "Art/Assets/frame-1.png", "Art/Assets/frame-2.png" , "Art/Assets/frame-3.png" , "Art/Assets/frame-4.png" , "Art/Assets/frame-5.png" , "Art/Assets/frame-6.png"  ,"Art/Assets/frame-7.png", "Art/Assets/frame-8.png" };


Sprite::~Sprite()
{
}

Sprite::Sprite()
{
	this->xPos = 0;
	this->yPos = 0;
	this->rot = 10;
	this->speed = 100;
	this->texture = Texture();
}

Sprite::Sprite(string imagePath, int numFrames)
{
	this->texture = Texture(imagePath);
	this->spritesheet = SpriteSheet(numFrames);
	this->xPos = 0;
	this->yPos = 0;
	this->rot = 0;
	this->speed = 100;

}

Sprite::Sprite(string imagePath, float _xPos, float _yPos, int numFrames)
{
	this->texture = Texture(imagePath);
	this->spritesheet = SpriteSheet(numFrames);
	this->currFrame = 4;
	this->numFrames = 9;
	this->xPos = _xPos;
	this->yPos = _yPos;
	this->rot = 0;
	this->speed = 100;
}


void Sprite::Update()
{
	this->currFrame = 1;
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

void Sprite::DetermineState()
{
	float xOff = 0.33f;
	float height = ceil((double)this->numFrames/3.0);
	float yOff = 1.0 / height;

	float xandOff = xOff * -1 + xOff * (this->currFrame % 3);
	float yandOff = yOff * -1 + yOff * (this->currFrame % (int)height);
	float xnoOff = xOff * (this->currFrame % 3);
	float ynoOff = yOff * (this->currFrame % (int)height);

	glTexCoord2f( xandOff, yandOff); glVertex2f(0, 0);
	cout << "BL: " << xandOff << " " << yandOff << endl;
	glTexCoord2f(xnoOff, yandOff); glVertex2f(this->texture.GetWidth(), 0);
	cout << "BR: " << xnoOff << " " << yandOff << endl;
	glTexCoord2f(xnoOff, ynoOff); glVertex2f(this->texture.GetWidth(), this->texture.GetHeight());
	cout << "TR: " << xnoOff << " " << ynoOff << endl;
	glTexCoord2f(xandOff,  ynoOff);	glVertex2f(0, this->texture.GetHeight());
	cout << "TL: " << xandOff << " " << ynoOff << endl;
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