#include "Sprite.h"

Sprite::~Sprite()
{
}

Sprite::Sprite()
{
	this->xPos = 0;
	this->yPos = 0;
	this->texture = Texture();
}

Sprite::Sprite(string imagePath)
{
	this->texture = Texture(imagePath);
	this->xPos = 0;
	this->yPos = 0;
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
	this->texture = Texture(imagePath);
	this->xPos = _xPos;
	this->yPos = _yPos;
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

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2f(0, 0);

	glTexCoord2f(1, 0);
	glVertex2f(this->texture.GetWidth(), 0);

	glTexCoord2f(1, 1);
	glVertex2f(this->texture.GetWidth(), this->texture.GetHeight());

	glTexCoord2f(0, 1);
	glVertex2f(0, this->texture.GetHeight());
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

