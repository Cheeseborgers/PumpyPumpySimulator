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

#include "State.h"

#include <utility>


// ---------------------------------------------------------------------------------------------------------------------

// Private Methods -----------------------------------------------------------------------------------------------------
// Constructor ---------------------------------------------------------------------------------------------------------
State::State(std::shared_ptr<sf::RenderWindow> window, std::stack<State *> *states)
{
    this->window = std::move(window);
    this->states = states;
    this->quit = false;
}
// ---------------------------------------------------------------------------------------------------------------------
State::~State() = default;
// Accessors -----------------------------------------------------------------------------------------------------------
const bool &State::getQuit() const
{
    return this->quit;
}
// Modifiers -----------------------------------------------------------------------------------------------------------
// Methods -------------------------------------------------------------------------------------------------------------
void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
// ---------------------------------------------------------------------------------------------------------------------

