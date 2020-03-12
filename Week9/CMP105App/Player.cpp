#include "Player.h"

Player::Player() {
	texture.loadFromFile("gfx/Goomba.png");
	setPosition(300, 300);
	setSize(sf::Vector2f(50, 50));
	setTexture(&texture);
}

Player::~Player() {

}

void Player::update(float dt) {

}

void Player::handleInput(float dt) {
	move(velocity * dt);
}