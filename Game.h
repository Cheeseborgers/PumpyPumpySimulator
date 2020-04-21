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

#ifndef PUMPYPUMPYSIMULATOR_GAME_H
#define PUMPYPUMPYSIMULATOR_GAME_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <ctime>
#include <memory>

class Game {

private:
    // Variables
    sf::VideoMode videoMode;
    std::unique_ptr<sf::RenderWindow> window;
    sf::Event sfmlEvent{};
    bool endGame{};

    // Private Methods
    void initVariables();

    void initWindow();

public:
    // Constructor
    Game();

    // Methods
    [[nodiscard]] bool running() const;

    void pollEvents();

    void update();

    void render();

};


#endif //PUMPYPUMPYSIMULATOR_GAME_H