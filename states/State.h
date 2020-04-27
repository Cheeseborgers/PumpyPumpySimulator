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

#ifndef PUMPYPUMPYSIMULATOR_STATE_H
#define PUMPYPUMPYSIMULATOR_STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <memory>
#include <stack>

class State;

class StateData
{
public:
    StateData() = default;

    //Variables
    sf::RenderWindow* window{};
    std::stack<State*>* states{};
};

class State {

private:
    // Private Methods

protected:
    std::stack<State*>* states{};
    std::shared_ptr<sf::RenderWindow> window;

    // Core
    bool quit{};

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

public:
    // Constructor
    explicit State(std::shared_ptr<sf::RenderWindow> window, std::stack<State *> *states);
    virtual ~State();

    // Accessors
    [[nodiscard]] const bool &getQuit() const;

    // Modifiers
    inline void endState() { this->quit = true; };

    // Methods
    virtual void updateMousePositions();
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};


#endif //PUMPYPUMPYSIMULATOR_STATE_H
