#include "Sprite.h"
#include "../Engine.h"

Sprite::~Sprite()
{
}

Sprite::Sprite()
{
	texture = Texture();
	pos = Vector3(0);
	rot = 0;
	speed = 250;
	scale = Vector3(1);
	size = Vector3(0);
}

Sprite::Sprite(string imagePath, int _spritesheetHeight, int _spritesheetWidth, int _spritesheetFrames)
{
	texture = Texture(imagePath);
	spritesheet = SpriteSheet(_spritesheetWidth, _spritesheetHeight, _spritesheetFrames);
	pos = Vector3(0);
	rot = 0;
	speed = 250;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetWidth(), 1);
}

Sprite::Sprite(string imagePath, Vector3 _v, int _spritesheetHeight, int _spritesheetWidth, int _spritesheetFrames)
{
	texture = Texture(imagePath);
	spritesheet = SpriteSheet(_spritesheetWidth, _spritesheetHeight, _spritesheetFrames);
	pos = _v;
	rot = 0;
	speed = 250;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetWidth(), 1);
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
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 0, 0, 1);
	glScalef(scale.x, scale.y, 1);

	// Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	DetermineState();
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void Sprite::SpriteNextFrame()
{
	spritesheet.NextFrame();
	spritesheet.SetFrame();
}

void Sprite::DetermineState()
{
	pair <float, float> TL = spritesheet.GetFrameTL();
	pair <float, float> BL = spritesheet.GetFrameBL();
	pair <float, float> TR = spritesheet.GetFrameTR();
	pair <float, float> BR = spritesheet.GetFrameBR();

	glTexCoord2f(BL.first, BL.second); glVertex2i(0, 0);
	/*cout << "BL: " << BL.first << " " << BL.second << endl;*/
	glTexCoord2f(BR.first, BR.second); glVertex2i(texture.GetWidth(), 0);
	/*cout << "BR: " << BR.first << " " << BR.second << endl;*/
	glTexCoord2f(TR.first, TR.second); glVertex2i(texture.GetWidth(), texture.GetHeight());
	/*cout << "TR: " << TR.first << " " << TR.second << endl;*/
	glTexCoord2f(TL.first,  TL.second);	glVertex2i(0, texture.GetHeight());
	/*cout << "TL: " << TL.first << " " << TL.second << endl;*/

}


void Sprite::SpeedTo(float x)
{
	speed = x;
}

void Sprite::SpeedBy(float x)
{
	speed += x;
}

void Sprite::MoveTo(Vector3 v)
{
	pos = v;
}

void Sprite::MoveBy(Vector3 v)
{
	pos = pos + (v * Engine::GetDT());
}

void Sprite::MoveLeft()
{
	pos = pos - Vector3((speed*Engine::GetDT()), 0, 0);
}

void Sprite::MoveRight()
{
	pos = pos + Vector3((speed*Engine::GetDT()), 0, 0);
}

void Sprite::MoveUp()
{
	pos = pos + Vector3(0, (speed*Engine::GetDT()), 0);
}

void Sprite::MoveDown()
{
	pos = pos - Vector3(0, (speed*Engine::GetDT()), 0);
}

void Sprite::RotateTo(float x)
{
	rot = x;
}
void Sprite::RotateBy(float x)
{
	rot += (x * Engine::GetDT());
}

void Sprite::SetScale(float x)
{
	scale = Vector3(x);
}

void Sprite::SetScale(Vector3 v)
{
	scale = v;
}

Vector3 * Sprite::GetPos()
{
	return &pos;
}

float * Sprite::GetRot()
{
	return &rot;
}

Vector3 * Sprite::GetScale()
{
	return &scale;
}

Vector3 * Sprite::GetSize()
{
	return &size;
}
