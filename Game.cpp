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
    this->endGame = false;
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::initPlayers()
{
    this->playerOne = std::make_unique<Player>();
}
//----------------------------------------------------------------------------------------------------------------------
void Game::initPlayerAreas()
{
    // Player one area
    this->playerOneArea.setSize(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y));
    this->playerOneArea.setFillColor(sf::Color::Red);
    this->playerOneArea.setOutlineColor(sf::Color::White);
    this->playerOneArea.setOutlineThickness(1.F);
    this->playerOneArea.setPosition(0.F, 0.F);

    // Player two area
    this->playerTwoArea.setSize(sf::Vector2f(this->playerOneArea.getSize().x, this->window->getSize().y));
    this->playerTwoArea.setFillColor(sf::Color::Green);
    this->playerTwoArea.setOutlineColor(sf::Color::Black);
    this->playerTwoArea.setOutlineThickness(1.F);
    this->playerTwoArea.setPosition(this->playerOneArea.getPosition().x + this->playerOneArea.getSize().x, 0.F);
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::initPlayerGUI()
{
    // Top Score board
    this->scoreBoard.setSize(sf::Vector2f(700.F, 120.F));
    this->scoreBoard.setFillColor(sf::Color::Black);
    this->scoreBoard.setOutlineColor(sf::Color::White);
    this->scoreBoard.setOutlineThickness(1.F);
    this->scoreBoard.setPosition(this->window->getSize().x / 2.F - this->scoreBoard.getSize().x / 2, 0.F);
}
// Constructor ---------------------------------------------------------------------------------------------------------
Game::Game()
{
    this->initVariables();

    this->initWindow();

    this->initPlayers();

    this->initPlayerAreas();

    this->initPlayerGUI();

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
        this->updatePollEvents();

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
void Game::updatePollEvents()
{
    sf::Event e{};

    while (this->window->pollEvent(e))
    {
        // Close game events ==================================================================
        if (e.Event::type == sf::Event::Closed)
        {
            this->window->close();
        }

        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
        {
            this->window->close();
        }
        // =====================================================================================
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::update()
{
    this->playerOne->update();
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::renderPlayerAreas(sf::RenderTarget &target)
{
    target.draw(this->playerOneArea);

    target.draw(this->playerTwoArea);
}
// ---------------------------------------------------------------------------------------------------------------------
void Game::renderPlayerGUI()
{
    this->window->draw(this->scoreBoard);
}
//----------------------------------------------------------------------------------------------------------------------
void Game::render()
{
    // Render Stuff
    this->window->clear(); // Clear default black

    this->renderPlayerAreas(*this->window); // Render Player areas

    this->renderPlayerGUI(); // Render scoreboard

    this->window->display(); // Display frame in window
}

void Game::initStateData() {

}

void Game::initStates()
{
    this->states.push(new IntroState(&this->stateData));
}

// ---------------------------------------------------------------------------------------------------------------------


