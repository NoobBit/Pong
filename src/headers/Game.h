#include <string>
#include <cstring>
#include <algorithm>

#include "raylib.h"

#include "Ball.h"
#include "Player.h"

class Game 
{
public:
    Game(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const std::string SCREEN_TITLE, const int FPS);
    
    void Loop();
    void Close();
private:
    void Init();
    void ScorePoint(Player &scoredPlayer, int scoreAmount);
    void ResetPositions(Player &player1, Player &player2, Ball &ball);
    void DrawFrontUI(Player &player1, Player &player2);
    void DrawBackUI();

    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    std::string SCREEN_TITLE;
    int FPS;

    double sineBounce;
};