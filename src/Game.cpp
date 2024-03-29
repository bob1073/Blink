#include "Game.h"

Game::Game()
    :
    window(sf::VideoMode(screenWidth, screenHeight), "Blink"),
    walls(0.0f, 0.0f, screenWidth, screenHeight),
    ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 0.0f, 1.0f }),
    paddle({ screenWidth / 3.0f, 8.0f * screenHeight / 10.0f })
{
    
    for (int rows = 0; rows < numRows; ++rows)
    {
        for (int cols = 0; cols < numCols; ++cols)
        {
            bricks[rows][cols] = Brick({ 50.0f + cols * Brick::GetWidth(), 50.0f + rows * Brick::GetHeight() }, sf::Color::Green);
        }
    }
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

    paddle.Update(dt, walls);
    paddle.DoBallCollision(ball);

    for (int rows = 0; rows < numRows; ++rows)
    {
        for (int cols = 0; cols < numCols; ++cols)
        {
            bricks[rows][cols].DoBallCollision(ball);
        }
    }
}

void Game::Render()
{
    window.clear();
    // Render things here
    ball.Render(window);
    paddle.Render(window);
    for (int rows = 0; rows < numRows; ++rows)
    {
        for (int cols = 0; cols < numCols; ++cols)
        {
            bricks[rows][cols].Render(window);
        }
    }
    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}
