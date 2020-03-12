#include "Sprite.h"

Sprite::Sprite() {

}

Sprite::~Sprite() {

}

void Sprite::update(float dt) {
	move(velocity * dt);
}