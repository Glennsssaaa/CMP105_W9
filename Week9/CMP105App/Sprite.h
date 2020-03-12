#pragma once
#include "Framework/GameObject.h"
class Sprite : public GameObject
{
public:
	Sprite();
	~Sprite();

	void update(float dt) override;
};

