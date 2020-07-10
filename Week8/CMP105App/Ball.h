#pragma once

#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <iostream>

class Ball : public GameObject, Collision {
public:

	sf::Texture texture;

	Ball();
	~Ball();

	void update(float dt);

	void collisionResponse(GameObject* collider);
};