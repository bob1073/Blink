#include "Paddle.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f pos)
	:
	pos(pos)
{
	paddle.setPosition(pos);
	paddle.setFillColor(sf::Color::Yellow);
	paddle.setSize(sf::Vector2f(width, height));

	wing1.setPosition(pos);
	wing1.setFillColor(sf::Color::Blue);
	wing1.setSize(sf::Vector2f(wingWidth, height));
	wing2.setPosition(pos.x + width - wingWidth, pos.y);
	wing2.setFillColor(sf::Color::Blue);
	wing2.setSize(sf::Vector2f(wingWidth, height));
}

void Paddle::Render(sf::RenderTarget& target)
{
	target.draw(paddle);
	target.draw(wing1);
	target.draw(wing2);
}

void Paddle::Update(const float& dt, const sf::FloatRect& walls)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pos.x -= speed * dt;
		std::cout << pos.x << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		pos.x += speed * dt;
	}

	pos.x = ClampScreen(pos.x, walls);

	SetPosition(pos);
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	sf::FloatRect paddleRect = paddle.getGlobalBounds();
	sf::FloatRect ballRect = ball.GetRect();

	// Collision happens
	if (paddleRect.intersects(ballRect))
	{
		const float distFromCenter = (ballRect.left + ballRect.width / 2.0f) - (pos.x + width / 2.0f);
		const float ratio = distFromCenter / (width / 2.0f);

		ball.Rebound({ ratio, -1.0f });

		return true;
	}

	return false;
}

float Paddle::ClampScreen(float x, const sf::FloatRect& walls)
{
	const float wallsRight = walls.left + walls.width;
	if (x <= walls.left)
	{
		return walls.left;
	}
	else if (x + width > wallsRight)
	{
		return wallsRight - width;
	}
	
	return x;
}

void Paddle::SetPosition(sf::Vector2f pos)
{
	paddle.setPosition(pos);
	wing1.setPosition(pos);
	wing2.setPosition(pos.x + width-wingWidth, pos.y);
}
