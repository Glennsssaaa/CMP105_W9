#pragma once
#include "SFML\Graphics.hpp"
#include "Framework\GameObject.h"
#include "Framework\Input.h"
class Player : public GameObject
{
public:
	Player();
	~Player();
	void update(float dt);
	void handleInput(float dt);
	sf::Vector2f velocity;

private:
	sf::Texture texture;
};

