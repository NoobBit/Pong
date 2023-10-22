#include "raylib.h"

class Player
{
public:
    Player(int paddleX, int paddleY, int paddleWidth, int paddleHeight, 
        float paddleSpeed, int paddleUpKey, int paddleDownKey, Color paddleColor);

    Rectangle paddleRect;

    int paddleUpKey;
    int paddleDownKey;
    float paddleSpeed;

    void Update();
    void Draw();
    void ResetPaddlePosition();

    int GetScore();
    void SetScore(int newScore);
private:
    int score;

    int paddleX;
    int paddleY;
    int paddleWidth;
    int paddleHeight;
    Color paddleColor;
};