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


#include "Player.h"
#include "states/IntroState.h"

class Game {

private:
    // Variables
    std::unique_ptr<sf::RenderWindow> window;
    sf::Event sfmlEvent{};

    // Game state stuff
    //TODO fix states and import order
    std::stack<State*> states;
    StateData stateData;

    // Player one
    std::unique_ptr<Player> playerOne;
    sf::RectangleShape playerOneArea;

    // player two
    sf::RectangleShape playerTwoArea;

    // Score board GUI
    sf::RectangleShape scoreBoard;

    // Game logic
    bool endGame{};

    // Private Methods
    void initVariables();
    void initPlayers();
    void initPlayerAreas();
    void initPlayerGUI();
    void initWindow();
    void initStateData();
    void initStates();

public:
    // Constructor
    Game();
    ~Game();

    // Methods
    void run();
    [[nodiscard]] bool running() const;

    void updatePollEvents();
    void update();
    void renderPlayerAreas(sf::RenderTarget &target);
    void renderPlayerGUI();
    void render();
};


#endif //PUMPYPUMPYSIMULATOR_GAME_H
