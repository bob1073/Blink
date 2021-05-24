#include "Brick.h"

Brick::Brick(sf::Vector2f pos, sf::Color color)
	:
	color(color)
{
	shape.setPosition(pos);
	shape.setFillColor(color);
	shape.setOutlineThickness(-padding);
	shape.setOutlineColor(sf::Color::Black);
	shape.setSize({ width, height });
}

void Brick::DoBallCollision(Ball& ball)
{
	const sf::FloatRect ballRect = ball.GetRect();
	const sf::FloatRect brickRect = shape.getGlobalBounds();

	if (ballRect.intersects(brickRect) && !isDestroyed)
	{
		isDestroyed = true;
		ball.ReboundY();
		
	}
	// WARNING: We need to implemment collision with edges!!
}

void Brick::Render(sf::RenderTarget& target)
{
	if (!isDestroyed)
	{
		target.draw(shape);
	}
}

float Brick::GetWidth()
{
	return width;
}

float Brick::GetHeight()
{
	return height;
}
