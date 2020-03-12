#include "BulletManager.h"

BulletManager::BulletManager() {
	texture.loadFromFile("gfx/sonic.png");

	for (int i = 0; i < 20; i++) {
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&texture);
		bullets[i].setSize(sf::Vector2f(25, 25));
	}
}

BulletManager::~BulletManager() {
}

void BulletManager::spawn() {
	for (int i = 0; i < bullets.size(); i++) {
		if (!bullets[i].isAlive()) {
			bullets[i].setAlive(true);
			bullets[i].setVelocity(150, 0);
			bullets[i].setPosition(spawnPoint);
			return;
		}
	}
}

void BulletManager::update(float dt, float x, float y) {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].isAlive()) {
			bullets[i].update(dt);
		}
	}
	spawnPoint = sf::Vector2f(x, y);
	deathCheck();
}

void BulletManager::deathCheck() {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].isAlive()) {
			if (bullets[i].getPosition().x > 1200) {
				bullets[i].setAlive(false);
			}
		}
	}
}

void BulletManager::render(sf::RenderWindow* window) {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].isAlive()) {
			window->draw(bullets[i]);
		}
	}
}

