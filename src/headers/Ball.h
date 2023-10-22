#include <math.h>
#include <random>

#include "raylib.h"

class Ball
{
public:
    Ball(int x, int y, int size, float xSpeed, float ySpeed, Color color);

    Rectangle rect;

    void Update();
    void Draw();

    void BounceX();
    void BounceY();
    void Reset();
private:
    float ConvertPositiveOrNegative(float number);

    int x;
    int y;
    int size;
    Color color;
    float xSpeed;
    float ySpeed;
    float xVelocity;
    float yVelocity;
};