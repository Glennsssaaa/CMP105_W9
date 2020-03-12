#include "BeachBallManager.h"
#include <iostream>

BeachBallManager::BeachBallManager() {
	spawnPoint = sf::Vector2f(350, 250);
	texture.loadFromFile("gfx/Beach_Ball.png");
	ballsAlive = 0;

	for (int i = 0; i < 21; i++) {
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BeachBallManager::~BeachBallManager() {}

void BeachBallManager::update(float dt) {
	for (int i = 0; i < balls.size()-1; i++) {
		if (balls[i].isAlive()) {
			balls[i].update(dt);
		}
	}
	deathCheck();
	std::cout << ballsAlive << "\n";
}

void BeachBallManager::spawn() {
	for (int i = 0; i < balls.size()-1; i++) {
		if (!balls[i].isAlive()) {
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			ballsAlive = ballsAlive + 1;
			return;
		}
	}

	if (ballsAlive == 20) {
		balls[20].setAlive(true);
		balls[20].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
		balls[20].setPosition(spawnPoint);
		ballsAlive = ballsAlive+1;
		return;
	}
	
}

void BeachBallManager::deathCheck() {
	for (int i = 0; i < balls.size()-1; i++) {
		if (balls[i].isAlive()) {
			if (balls[i].getPosition().x < -100) {
				balls[i].setAlive(false);
				ballsAlive = ballsAlive - 1;
			}
			if (balls[i].getPosition().x > 800) {
				balls[i].setAlive(false);
				ballsAlive = ballsAlive - 1;
			}
			if (balls[i].getPosition().y < -100) {
				balls[i].setAlive(false);
				ballsAlive = ballsAlive - 1;
			}
			if (balls[i].getPosition().y > 600) {
				balls[i].setAlive(false);
				ballsAlive = ballsAlive - 1;
			}
		}
	}
}

void BeachBallManager::render(sf::RenderWindow* window) 
{
	for (int i = 0; i < balls.size()-1; i++) {
		if (balls[i].isAlive()) {
			window->draw(balls[i]);
		}
	}
}