#include "Game.h"

Game::Game()
	: window(sf::VideoMode(screenWidth, screenHeight), "Blink")
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

}

void Game::Render()
{
    window.clear();
    // Render things here

    //
    window.display();
}

bool Game::IsRunning() const
{
    return running;
}
