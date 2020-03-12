#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "BeachBallManager.h"
#include "SpriteManager.h"
#include "Player.h"
#include "BulletManager.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	BeachBallManager manager;
	SpriteManager spritemanager;
	Player player;
	BulletManager bulletmanager;


	float playerX;
	float playerY;
	float spacepressed;
	float Gpressed;
};