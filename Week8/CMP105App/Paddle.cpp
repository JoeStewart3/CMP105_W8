#include "Paddle.h"

Paddle::Paddle() {
	velocity.x = 0;
	velocity.y = 0;
}
Paddle::~Paddle() {}

void Paddle::handleInputLeft(float dt, Input* input) {
	if (input->isKeyDown(sf::Keyboard::Up) == false && input->isKeyDown(sf::Keyboard::Down) == false && input->isKeyDown(sf::Keyboard::Right) == false && input->isKeyDown(sf::Keyboard::Left) == false) {
		velocity.x = 0;
		velocity.y = 0;
	}
	if (input->isKeyDown(sf::Keyboard::Up)) {
		std::cout << "Up pressed";
		velocity.y = -1;
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		std::cout << "Down pressed";
		velocity.y = 1;
	}
	move(velocity * dt * 500.f);
}

void Paddle::handleInputRight(float dt, Input* input) {
	setPosition(getPosition().x, input->getMouseY());
}

void Paddle::update(float dt) {


}

void Paddle::collisionResponse(GameObject* collider) {


}