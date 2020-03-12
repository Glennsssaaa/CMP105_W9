#pragma once
#include <math.h>
#include <vector>
#include "Bullet.h"
#include "Player.h"
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void spawn();
	void update(float dt, float x, float y);
	void render(sf::RenderWindow* window);
	void deathCheck();

private:
	std::vector<Bullet> bullets;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
};

