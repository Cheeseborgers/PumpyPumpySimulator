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

#ifndef PUMPYPUMPYSIMULATOR_INTROSTATE_H
#define PUMPYPUMPYSIMULATOR_INTROSTATE_H

#include "MainMenuState.h"
#include "GameState.h"


class IntroState : public State
{
private:
    sf::RectangleShape background;
    sf::Texture bgTexture;

    sf::Clock clock;
    float introTimerMax{};

    // Private Methods
    void initBackground();

public:
    // Constructor
    IntroState(std::shared_ptr<sf::RenderWindow> window, std::stack<State *> *states);

    // Methods
    void update(const float &dt) override;
    void render(sf::RenderTarget& target) override;

};


#endif //PUMPYPUMPYSIMULATOR_INTROSTATE_H
