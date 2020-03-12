#pragma once
#include <vector>
#include <math.h>
#include "Sprite.h"

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);

private:
	std::vector<Sprite> sprites;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	int spritesAlive;
};

