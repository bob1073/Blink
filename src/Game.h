#pragma once

#include "Paddle.h"
#include "Brick.h"

class Game
{
public:
	Game();
	~Game();

	void UpdateEvents();
	void Update();
	void Render();

	bool IsRunning() const;
	// User functions here

	//
private:
	sf::RenderWindow window;
	sf::Event e;

	bool running = true;
	sf::Clock dtClock;

	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;

	// User variables here
	/* Entities */
	sf::FloatRect walls;
	Ball ball;
	Paddle paddle;
	Brick brick;
	//
};