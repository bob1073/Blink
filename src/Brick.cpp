#include "Brick.h"

Brick::Brick(sf::Vector2f pos, sf::Color color)
	:
	color(color)
{
	shape.setPosition(pos);
	shape.setFillColor(color);
	shape.setOutlineThickness(padding);
	shape.setOutlineColor(sf::Color::Transparent);
	shape.setSize({ width, height });
}

void Brick::DoBallCollision(Ball& ball)
{
	const sf::FloatRect ballRect = ball.GetRect();
	const sf::FloatRect brickRect = shape.getGlobalBounds();

	if (ballRect.intersects(brickRect) && !isDestroyed)
	{
		ball.ReboundY();
		isDestroyed = true;
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
