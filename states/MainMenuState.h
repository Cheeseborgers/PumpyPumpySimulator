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

#ifndef PUMPYPUMPYSIMULATOR_MAINMENUSTATE_H
#define PUMPYPUMPYSIMULATOR_MAINMENUSTATE_H

#include "GameState.h"
#include "../GUI/Button.h"


class MainMenuState  : public State{

private:
    sf::Font font;
    sf::RectangleShape background;
    sf::Texture bgTexture;

    std::map<std::string, std::unique_ptr<Button>> buttons;

    // Private Methods
    void initBackground();
    void initFonts();
    void initButtons();

public:

    // Constructor
    MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<State *> *states);

    // Accessors

    // Modifiers

    // Methods
    void updateButtons();
    void update(const float &dt) override;

    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget& target) override;

};


#endif //PUMPYPUMPYSIMULATOR_MAINMENUSTATE_H
