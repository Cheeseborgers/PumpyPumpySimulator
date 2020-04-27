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

#include "MainMenuState.h"



// Private Methods -----------------------------------------------------------------------------------------------------
void MainMenuState::initBackground()
{

    this->background.setSize(sf::Vector2f(
            static_cast<float>(this->window->getSize().x),
            static_cast<float >(this->window->getSize().y))
    );

    std::cout << "Loaded texture 111\n";

    if (!this->bgTexture.loadFromFile("assets/images/bg.png"))
    {
        throw std::runtime_error ("ERROR::MAINMENUSTATE::INITBACKGROUND: Could not load assets/images/bg1.png");
    }

    this->background.setTexture(&this->bgTexture);
}
// ---------------------------------------------------------------------------------------------------------------------
void MainMenuState::initFonts()
{
    if (!this->font.loadFromFile("assets/fonts/Dosis-Light.ttf"))
    {
        throw std::runtime_error ("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = std::make_unique<Button>(
            300.F, 480.F,
            250.F, 50.F,
            &this->font,
            "New Game",
            50,
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0)
    );

    this->buttons["EXIT_STATE"] = std::make_unique<Button>(
            300.F, 580.F,
            250.F, 50.F,
            &this->font,
            "Exit",
            50,
            sf::Color(70, 70, 70, 200),
            sf::Color(250, 250, 250, 250),
            sf::Color(20, 20, 20, 50),

            sf::Color(70, 70, 70, 0),
            sf::Color(150, 150, 150, 0),
            sf::Color(20, 20, 20, 0)
    );
}
// Constructor ---------------------------------------------------------------------------------------------------------
MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> window,
                             std::stack<State *> *states)
    : State(std::move(window), states) {

  this->initBackground();
  this->initFonts();
  this->initButtons();
}
// Methods -------------------------------------------------------------------------------------------------------------
void MainMenuState::updateButtons()
{
    /* @return void
     * Updates all the buttons in the state and handles their
     * functionality.
     * */

    for (auto &i : this->buttons)
    {
        i.second->update(this->mousePosView);
    }

    // New game
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->states));
    }

    // Quit the game
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit = true;
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();

    this->updateButtons();
}
// ---------------------------------------------------------------------------------------------------------------------
void MainMenuState::renderButtons(sf::RenderTarget& target)
{
    for (auto &i : this->buttons)
    {
        i.second->render(&target);
    }
}
// ---------------------------------------------------------------------------------------------------------------------
void MainMenuState::render(sf::RenderTarget& target)
{
    // Render Background
    target.draw(this->background);

    this->renderButtons(target);
}
// ---------------------------------------------------------------------------------------------------------------------
