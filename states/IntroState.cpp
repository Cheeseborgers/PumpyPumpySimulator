//
//      Created by Goodecheeseburgers on 22/04/2020.
//      PumpyPumpySimulator. A random C++ / SFML game.
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

#include "IntroState.h"

#include <utility>

// Private Methods -----------------------------------------------------------------------------------------------------
void IntroState::initBackground()
{

    this->background.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x),
            static_cast<float >(this->window->getSize().y))
    );

    if (!this->bgTexture.loadFromFile("assets/images/intro.png"))
    {
        throw std::runtime_error ("ERROR::MAINMENUSTATE::INITBACKGROUND: Could not load assets/images/intro.png");
    }

    this->background.setTexture(&this->bgTexture);
}
// Constructor ---------------------------------------------------------------------------------------------------------
IntroState::IntroState(std::shared_ptr<sf::RenderWindow> window,
                       std::stack<State *> *states)
    : State(std::move(window), states) {

  this->introTimerMax = 2.5F;
  this->initBackground();
}
// Methods -------------------------------------------------------------------------------------------------------------
void IntroState::update(const float &dt)
{
    this->updateMousePositions();

    if (this->clock.getElapsedTime().asSeconds() < this->introTimerMax)
    {

    } else {
        this->states->push(new MainMenuState(this->window, this->states));
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void IntroState::render(sf::RenderTarget& target)
{
    // Render Background
    target.draw(this->background);
}
// ---------------------------------------------------------------------------------------------------------------------
