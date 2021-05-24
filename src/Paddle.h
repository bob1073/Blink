#pragma once

#include "Ball.h"

class Paddle
{
public:
	// Constructor
	Paddle(sf::Vector2f pos);

	// Render
	void Render(sf::RenderTarget& target);

	// Movement
	void Update(const float& dt, const sf::FloatRect& walls);

	// Collision
	bool DoBallCollision(Ball& ball) const;

private:
	// Shape
	sf::RectangleShape paddle;
	sf::RectangleShape wing1;
	sf::RectangleShape wing2;
	static constexpr float wingWidth = 25.0f;
	static constexpr float width = 150.0f;
	static constexpr float height = 25.0f;

	// Movement
	sf::Vector2f pos;
	static constexpr float speed = 500.0f;

	void SetPosition(sf::Vector2f pos);

	// Keep paddle inside the walls
	float ClampScreen(float x, const sf::FloatRect& walls);
};

