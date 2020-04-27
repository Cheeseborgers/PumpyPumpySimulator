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

#include "Button.h"

// Private Methods -----------------------------------------------------------------------------------------------------
void Button::initShape(float &posX, float &posY, float &width, float &height)
{
    this->shape.setFillColor(this->idleColor);

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(posX, posY);
}
// ---------------------------------------------------------------------------------------------------------------------
void Button::initText(const std::string &string, const unsigned& characterSize)
{
    this->text.setFont(*this->font);
    this->text.setString(string);
    this->text.setFillColor(this->textIdleColor);
    this->text.setCharacterSize(characterSize);
    this->text.setPosition(
        this->shape.getPosition().x +
            (this->shape.getGlobalBounds().width / 2.F) -
            this->text.getGlobalBounds().width / 2.F,
        this->shape.getPosition().y +
            ((this->shape.getGlobalBounds().height - 4.F) / 2.F) -
            this->text.getGlobalBounds().height / 2.F);
}
// ----------------------------------------------------------------------------------------------------------------------
// Constructor ---------------------------------------------------------------------------------------------------------
Button::Button(float x, float y, float width, float height, sf::Font *font,
               const std::string &text, unsigned characterSize,
               sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {

    this->buttonState = BTN_IDLE;

    this->textIdleColor = textIdleColor;
    this->textHoverColor = textHoverColor;
    this->textActiveColor = textActiveColor;

    this->idleColor = idleColor;
    this->activeColor = activeColor;
    this->hoverColor = hoverColor;

    this->initShape(x, y, width, height);

    this->font = font;
    this->initText(text, characterSize);
}
// Accessors -----------------------------------------------------------------------------------------------------------
// Modifiers -----------------------------------------------------------------------------------------------------------
// Methods -------------------------------------------------------------------------------------------------------------
void Button::update(const sf::Vector2f mousePos)
{
    /* @return void
     * Updates the button state
     * */

    // Idle
    this->buttonState = BTN_IDLE;

    // Hover
    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        // Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
            std::cout << "Pressed\n";
        }
    }

    // Change button and text color on state
    switch (this->buttonState)
    {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->text.setFillColor(this->textIdleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->text.setFillColor(this->textHoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            this->text.setFillColor(this->textActiveColor);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            this->text.setFillColor(sf::Color::Blue);
            break;
    }
}
// -------------------------------------------------------------------------------------------------------
void Button::render(sf::RenderTarget *target)
{
    /* @return void
     * Renders the button shape and text
     * to the current frame
     * -Renders button shape
     * -Renders button text
     * */

    target->draw(this->shape);
    target->draw(this->text);
}




