#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space) && !spacepressed) {
		//manager.spawn();
		bulletmanager.spawn();
		spacepressed = true;
	}
	if (!input->isKeyDown(sf::Keyboard::Space)) {
		spacepressed = false;
	}

	if (input->isKeyDown(sf::Keyboard::G) && !Gpressed) {
		spritemanager.spawn();
		Gpressed = true;
	}
	if (!input->isKeyDown(sf::Keyboard::G)) {
		Gpressed = false;
	}

	if (input->isKeyDown(sf::Keyboard::W)) {
		player.velocity.y = -100.f;
	}
	else if (input->isKeyDown(sf::Keyboard::S)) {
		player.velocity.y = 100.f;
	}

	if (input->isKeyDown(sf::Keyboard::A)) {
		player.velocity.x = -100.f;
	}
	else if (input->isKeyDown(sf::Keyboard::D)) {
		player.velocity.x = 100.f;
	}
	player.handleInput(dt);

	player.velocity.x = 0.f;
	player.velocity.y = 0.f;
}

// Update game objects
void Level::update(float dt)
{
	playerX = player.getPosition().x;
	playerY = player.getPosition().y;
	manager.update(dt);
	spritemanager.update(dt);
	bulletmanager.update(dt, playerX, playerY);
	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	manager.render(window);
	spritemanager.render(window);
	bulletmanager.render(window);
	window->draw(player);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}