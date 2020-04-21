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
void Game::initWindow() {
    this->videoMode = sf::VideoMode(800, 600); // Set video mode

    this->window = std::make_unique<sf::RenderWindow>( // Create window
            this->videoMode,
            "PumpyPumpySimulator",
            sf::Style::Titlebar | sf::Style::Close
    );

    this->window->setFramerateLimit(60); // Set framerate

    this->window->setVerticalSyncEnabled(false); // Set Vsync to false;
}

// ---------------------------------------------------------------------------------------------------------------------
void Game::initVariables() {
    this->endGame = false;
}

// Constructor ---------------------------------------------------------------------------------------------------------
Game::Game() {
    this->initVariables();

    this->initWindow();
}

// ---------------------------------------------------------------------------------------------------------------------
bool Game::running() const {
    return this->window->isOpen();
}

// ---------------------------------------------------------------------------------------------------------------------
void Game::pollEvents() {
    while (this->window->pollEvent(this->sfmlEvent)) {
        switch (this->sfmlEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->sfmlEvent.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
            default:
                break;

        }
    }
}

// ---------------------------------------------------------------------------------------------------------------------
void Game::update() {
    this->pollEvents(); // Poll sfml events

    // Update stuff
}

// ---------------------------------------------------------------------------------------------------------------------
void Game::render() {
    // Render Stuff
    this->window->clear(); // Clear default black

    this->window->display(); // Display frame in window
}
// ---------------------------------------------------------------------------------------------------------------------
