//
//      Created by Goodecheeseburgers on 27/04/2020.
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

#ifndef PUMPYPUMPYSIMULATOR_GAMESTATE_H
#define PUMPYPUMPYSIMULATOR_GAMESTATE_H

#include "State.h"
#include "../Player.h"

class GameState  : public State{

private:
    // Player one
    std::unique_ptr<Player> playerOne;
    sf::RectangleShape playerOneArea;

    // player two
    sf::RectangleShape playerTwoArea;

    // Score board GUI
    sf::RectangleShape scoreBoard;

    // Private Methods
    void initPlayerAreas();
    void initPlayers();
    void initPlayerGUI();

public:

    // Constructor
    GameState(std::shared_ptr<sf::RenderWindow> window, std::stack<State *> *states);

    // Accessors

    // Modifiers

    // Methods
    void update(const float &dt) override;

    void renderPlayerAreas(sf::RenderTarget& target);
    void renderPlayerGUI(sf::RenderTarget& target);
    void render(sf::RenderTarget& target) override;

};


#endif //PUMPYPUMPYSIMULATOR_GAMESTATE_H
