#include "Game.h"

Game::Game()
	: 
    window(sf::VideoMode(screenWidth, screenHeight), "Blink"),
    walls(0.0f, 0.0f, screenWidth, screenHeight),
    ball({ screenWidth / 2.0f, screenHeight / 2.0f }, {0.0f, 1.0f})
{
}

Game::~Game()
{
}

void Game::UpdateEvents()
{
    while (window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            running = false;
    }
}

void Game::Update()
{
    const float dt = dtClock.restart().asSeconds();

    ball.Update(dt);
    ball.DoWallCollisions(walls);

    if (ball.Falls(walls.top + walls.height))
    {
        ball.Respawn();
    }
}

void Game::Render()
{
    window.clear();
    // Render things here
    ball.Render(window);
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}
