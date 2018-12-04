#ifndef GAME_RIGIDBODY
#define GAME_RIGIDBODY

#include "../Math/Vector3.h"
#include "../Engine.h"

class Rigidbody
{
public:
	~Rigidbody();
	Rigidbody();

	void Initialize(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size);
	void Update();
	void Render(Vector3 c);
	
	void AddForce(Vector3 f);

private:
	Vector3* pos;
	Vector3* scale;
	Vector3* size;
	float* rot;

	float gravity;
	float friction;
	Vector3 vel;
};

#endif

