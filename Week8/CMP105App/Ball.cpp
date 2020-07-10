#include "Ball.h"

Ball::Ball() {}
Ball::~Ball() {}

void Ball::update(float dt) {
	move(velocity * dt);

	if (getPosition().y > 600) {
		setPosition(getPosition().x, 600);
		velocity.y = -velocity.y;
	}
	if (getPosition().y < 0) {
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
	}
	if (getPosition().x > 1200) {
		setPosition(600, 300);
		velocity.x = -velocity.x;
	}
	if (getPosition().x < 0) {
		setPosition(600, 300);
		velocity.x = -velocity.x;
	}
}

void Ball::collisionResponse(GameObject* collider) {
	velocity.x = -velocity.x;
}