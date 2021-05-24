#pragma once

#include "Ball.h"

class Brick
{
public:
	// Constructor
	Brick(sf::Vector2f pos, sf::Color color);

	// Update
	void DoBallCollision(Ball& ball);

	// Render
	void Render(sf::RenderTarget& target);

private:
	// Appearance
	static constexpr float width = 75.0f;
	static constexpr float height = 25.0f;
	static constexpr float padding = 1.0f;
	sf::RectangleShape shape;
	sf::Color color;

	// State
	bool isDestroyed = false;

};

