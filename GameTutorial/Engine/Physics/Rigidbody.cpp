#include "Rigidbody.h"

Rigidbody::Rigidbody()
{
	this->friction = 1;
	this->gravity = 0;	
}

void Rigidbody::Initialize(float _friction, float _gravity, Vector3 * _pos, float * _rot, Vector3 * _scale, Vector3* _size)
{
	this->friction = _friction;
	this->gravity = _gravity;

	this->pos = _pos;
	this->rot = _rot;
	this->scale = _scale;
	this->size = _size;
}

void Rigidbody::Update()
{
	vel.x *= friction;
	vel.y += gravity;

	*pos = *pos + (vel * Engine::GetDT());
}

void Rigidbody::Render(Vector3 c)
{
	glLoadIdentity();

	glTranslatef(pos->x, pos->y, pos->z);
	glRotatef(*rot, 0, 0, 1);
	glScalef(scale->x, scale->y, scale->z);

	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{
		glVertex2i(0, 0);
		glVertex2i((int)size->x, 0);

		glVertex2i((int)size->x, 0);
		glVertex2i((int)size->x, (int)size->y);

		glVertex2i((int)size->x, (int)size->y);
		glVertex2i(0, (int)size->y);

		glVertex2i(0, (int)size->y);
		glVertex2i(0, 0);
	}
	glEnd();
}

void Rigidbody::AddForce(Vector3 f)
{
	vel = vel + f;
}


Rigidbody::~Rigidbody()
{
}
