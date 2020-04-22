//
//      Created by Goodecheeseburgers on 22/04/2020.
//      SomeRPG. A C++ console role playing game.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/SomeRPG
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

#ifndef PUMPYPUMPYSIMULATOR_PLAYER_H
#define PUMPYPUMPYSIMULATOR_PLAYER_H

#include "Pump.h"

class Player {

private:
    unsigned int points{};
    std::unique_ptr<Pump> pump;

    // Private methods
    void initPump();

public:

    // Constructor
    Player();

    // Accessors

    // Modifiers

    // Methods
    void update();
    void render();

};

// NS END

#endif //PUMPYPUMPYSIMULATOR_PLAYER_H
