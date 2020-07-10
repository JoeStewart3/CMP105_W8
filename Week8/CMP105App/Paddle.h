#pragma once

#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <iostream>

class Paddle : public GameObject, Collision {
public:
	Paddle();
	~Paddle();

	void handleInputLeft(float dt, Input* in);

	void handleInputRight(float dt, Input* in);

	void update(float dt);

	void collisionResponse(GameObject* collider);
};