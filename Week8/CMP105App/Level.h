#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Ball.h"
#include "Paddle.h"
#include <string>
#include <iostream>


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

	// Level Objects
	Ball ball1;
	Paddle LeftPaddle;
	Paddle RightPaddle;
	sf::RectangleShape CBox;
	sf::Texture texture;
};