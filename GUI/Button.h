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

#ifndef DOOEY_REBORN_BUTTON_H
#define DOOEY_REBORN_BUTTON_H

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

enum buttonStates {BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button {

private:
    short unsigned buttonState;
    sf:: RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color textIdleColor;
    sf::Color textHoverColor;
    sf::Color textActiveColor;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    // Private Methods
    void initShape(float &posX, float &posY, float &width, float &height);
    void initText(const std::string &string, const unsigned& characterSize);

public:

    // Constructor
    Button(float x, float y, float width, float height, sf::Font *font,
            const std::string &text, unsigned characterSize,
            sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor
            );

    // Accessors
    inline bool isPressed() const {return this->buttonState == BTN_ACTIVE; };

    // Modifiers

    // Methods
    void update(sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);

};


#endif //DOOEY_REBORN_BUTTON_H
