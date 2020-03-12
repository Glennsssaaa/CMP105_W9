#include "SpriteManager.h"
#include <iostream>

SpriteManager::SpriteManager(){
	texture.loadFromFile("gfx/Mushroom.png");

	for (int i = 0; i < 40; i++) {
		sprites.push_back(Sprite());
		sprites[i].setAlive(false);
		sprites[i].setTexture(&texture);
		sprites[i].setSize(sf::Vector2f(100, 100));
	}

	spritesAlive = 0;
}

SpriteManager::~SpriteManager() {

}

void SpriteManager::spawn() {
	for (int i = 0; i < sprites.size(); i++) {
		if (!sprites[i].isAlive()) {
			sprites[i].setAlive(true);
			sprites[i].setPosition(sf::Vector2f(rand() % 1100 + 100, -10));
			sprites[i].setVelocity(0, 100);
			spritesAlive = spritesAlive + 1;
			return;
		}
	}
}

void SpriteManager::update(float dt) {
	for (int i = 0; i < sprites.size(); i++) {
		if (sprites[i].isAlive()) {
			sprites[i].update(dt);
		}
	}
	deathCheck();
	std::cout << spritesAlive << "\n";
}

void SpriteManager::deathCheck() {
	for (int i = 0; i < sprites.size(); i++) {
		if (sprites[i].isAlive()) {
			if (sprites[i].getPosition().y > 700) {
				sprites[i].setAlive(false);
				spritesAlive = spritesAlive - 1;
			}
		}
	}
}

void SpriteManager::render(sf::RenderWindow* window) {
	for (int i = 0; i < sprites.size(); i++) {
		if (sprites[i].isAlive()) {
			window->draw(sprites[i]);
		}
	}
}


