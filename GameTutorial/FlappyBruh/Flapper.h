#ifndef GAME_FLAPPER
#define GAME_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"

class Flapper
{
public:
	Flapper();
	~Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();

	void Jump();

	Sprite& GetSprite();
	Rigidbody& GetRB();

private:
	Sprite sprite;
	Rigidbody rb;
};

#endif