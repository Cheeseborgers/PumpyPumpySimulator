//
//      Created by Goodecheeseburgers on 21/04/2020.
//      PumpyPumpySimulator. A C++ / SFML game.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/PumpyPumpySimulator
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include "Game.h"

// Private Methods -----------------------------------------------------------------------------------------------------
void Game::initWindow()
{
    this->window = std::make_unique<sf::RenderWindow>( // Create window
            sf::VideoMode::getDesktopMode(),
            "PumpyPumpySimulator",
            sf::Style::Titlebar | sf::Style::Resize
    );

    this->window->setFramerateLimit(60); // Set framerate

    this->window->setVerticalSyncEnabled(false); // Set Vsync to false;
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::initVariables()
{
    this->window = nullptr;
    this->dt = 0.F;
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::initStateData() {

}
// ---------------------------------------------------------------------------------------------------------------------
void Game::initStates()
{
    this->states.push(new IntroState(this->window, &this->states));
}
// Constructor ---------------------------------------------------------------------------------------------------------
Game::Game()
{
    this->initVariables();

    this->initWindow();

    // State Stuff (intro state)
    this->initStateData();
    this->initStates();
}
// Destructor ----------------------------------------------------------------------------------------------------------
Game::~Game()
{
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();

        this->update();

        this->render();
    }
}
// ---------------------------------------------------------------------------------------------------------------------
bool Game::running() const
{
    return this->window->isOpen();
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::updateDt()
{
    /* @return void
     * Updates the dt variable with the time it takes
     * to update and render one frame*/

    this->dt = this->dtClock.restart().asSeconds();
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::updateEvents()
{
    sf::Event ev{};

    while (this->window->pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
        {
            this->window->close();
        }

        if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
        {
            this->window->close();
        }
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::update()
{
    this->updateEvents();

    // update the current state
    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Game end
    else {
        endGame();
        this->window->close();
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Game::render()
{
    // Render Stuff
    this->window->clear(); // Clear default black

    this->states.top()->render(*this->window);

    this->window->display(); // Display frame in window
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::endGame()
{
    std::cout << "Game ended!\n";
}
// ---------------------------------------------------------------------------------------------------------------------


