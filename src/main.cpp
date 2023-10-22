#include "headers\Game.h"

int main() {
    Game game(750, 500, "Pong!", 60);
    game.Loop();
    game.Close();

    /* TODOS:
        - Add Difficulty Curve
        - Add Music & SFX
        - Add Debug Menu
        - Add Main Menu
        - Add New Features
    */
    return 0;
}