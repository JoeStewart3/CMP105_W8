#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball1.texture.loadFromFile("gfx/Beach_Ball.png");

	ball1.setTexture(&ball1.texture);
	ball1.setSize(sf::Vector2f(75, 75));
	ball1.setPosition(300, 300);
	ball1.setCollisionBox(sf::FloatRect(0,0,75,75));
	ball1.setVelocity(-500, 100);

	LeftPaddle.setSize(sf::Vector2f(25, 150));
	LeftPaddle.setPosition(1100, 300);
	LeftPaddle.setFillColor(sf::Color::Red);
	LeftPaddle.setCollisionBox(sf::FloatRect(0, 0, 25, 150));

	RightPaddle.setSize(sf::Vector2f(25, 150));
	RightPaddle.setPosition(100, 300);
	RightPaddle.setFillColor(sf::Color::Red);
	RightPaddle.setCollisionBox(sf::FloatRect(0, 0, 25, 150));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	LeftPaddle.handleInputLeft(dt, input);
	RightPaddle.handleInputRight(dt, input);
}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt); 

	if (Collision::checkBoundingBox(&ball1, &LeftPaddle)) {
		std::cout << "COLLISION!";
		ball1.collisionResponse(NULL); 
		LeftPaddle.collisionResponse(NULL); 
	}
	if (Collision::checkBoundingBox(&ball1, &RightPaddle)) {
		std::cout << "COLLISION!";
		ball1.collisionResponse(NULL);
		RightPaddle.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(LeftPaddle);
	window->draw(RightPaddle);
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