#include "Ball.h"

Ball::Ball(const sf::Vector2f& startPos, const sf::Vector2f& startDir)
	:
	startPos(startPos),
	startDir(startDir),
	pos(startPos),
	dir(startDir),
	speed(startSpeed)
{
	NormalizeDir();

	ball.setPosition(pos);
	ball.setRadius(radius);
	ball.setFillColor(sf::Color::Cyan);
}

void Ball::Render(sf::RenderTarget& target)
{
	target.draw(ball);
}

void Ball::Update(const float& dt)
{
	pos += dir * speed * dt;
	ball.setPosition(pos);
}

void Ball::ReboundX()
{
	dir.x = -dir.x;
}

void Ball::ReboundY()
{
	dir.y = -dir.y;
}

void Ball::Rebound(sf::Vector2f dir)
{
	this->dir = dir;
}

void Ball::IncrementSpeed()
{
	speed += speedRate;
}

void Ball::Respawn()
{
	pos = startPos;
	dir = startDir;
	speed = startSpeed;
}

bool Ball::Falls(float bottomWalls) const
{
	const float margin = 200.0f;
	if (pos.y > bottomWalls + margin)
	{
		return true;
	}

	return false;
}

bool Ball::DoWallCollisions(const sf::FloatRect& walls)
{
	const float right = walls.left + walls.width;
	const float bottom = walls.top + walls.height;

	if(pos.y <= walls.top)
	{
		ReboundY();
		return true;
	}

	if (pos.x < walls.left || pos.x > right)
	{
		ReboundX();
		return true;
	}

	return false;
}

sf::FloatRect Ball::GetRect() const
{
	return ball.getGlobalBounds();
}

const sf::Vector2f Ball::GetPosition() const
{
	return pos;
}

const sf::Vector2f Ball::GetDirection() const
{
	return dir;
}

void Ball::NormalizeDir()
{
	const float norm = std::sqrt(dir.x * dir.x + dir.y * dir.y);

	dir /= norm;
}