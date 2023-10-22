#include "headers\Player.h"

Player::Player(int paddleX, int paddleY, int paddleWidth, int paddleHeight, 
                float paddleSpeed, int paddleUpKey, int paddleDownKey, Color paddleColor)
{
    this->paddleX = paddleX;
    this->paddleY = paddleY;
    this->paddleWidth = paddleWidth;
    this->paddleHeight = paddleHeight;
    this->paddleUpKey = paddleUpKey;
    this->paddleDownKey = paddleDownKey;
    this->paddleSpeed = paddleSpeed;
    this->paddleColor = paddleColor;

    this->score = 0;

    this->paddleRect = Rectangle {
        static_cast<float>(this->paddleX), static_cast<float>(this->paddleY),
        static_cast<float>(this->paddleWidth), static_cast<float>(this->paddleHeight)
    };
}

int Player::GetScore()
{
    return this->score;
}

void Player::SetScore(int newScore)
{
    this->score = newScore;
}

void Player::ResetPaddlePosition()
{
    this->paddleRect.x = this->paddleX;
    this->paddleRect.y = this->paddleY;
}

void Player::Update()
{
    if (IsKeyDown(this->paddleUpKey) && this->paddleRect.y > 0)
    {
        this->paddleRect.y -= this->paddleSpeed;
    }

    if (IsKeyDown(this->paddleDownKey)  && this->paddleRect.y < GetScreenHeight() - this->paddleHeight)
    {
        this->paddleRect.y += this->paddleSpeed;
    }
}

void Player::Draw()
{
    DrawRectangleRec(this->paddleRect, this->paddleColor);
}