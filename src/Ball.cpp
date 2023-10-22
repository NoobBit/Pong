#include "headers\Ball.h"

Ball::Ball(int x, int y, int size, float xSpeed, float ySpeed, Color color)
{
    this->x = x;
    this->y = y;
    this->size = size;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
    this->color = color;
    this->xVelocity = this->ConvertPositiveOrNegative(this->xSpeed);
    this->yVelocity = this->ConvertPositiveOrNegative(this->ySpeed);

    this->rect = Rectangle {
        static_cast<float>(this->x), static_cast<float>(this->y),
        static_cast<float>(this->size), static_cast<float>(this->size)
    };
}

void Ball::Update()
{
    this->rect.x += this->xVelocity;
    this->rect.y += this->yVelocity;
}

void Ball::Draw()
{
    DrawRectangleRec(this->rect, this->color);
}

void Ball::BounceX()
{
    this->xVelocity > 0 ? this->xVelocity = -this->xVelocity : this->xVelocity = abs(this->xVelocity);
}

void Ball::BounceY()
{
    this->yVelocity > 0 ? this->yVelocity = -this->yVelocity : this->yVelocity = abs(this->yVelocity);
}

void Ball::Reset()
{
    this->rect.x = this->x;
    this->rect.y = this->y;

    this->xVelocity = this->ConvertPositiveOrNegative(this->xSpeed);
    this->yVelocity = this->ConvertPositiveOrNegative(this->ySpeed);
}

float Ball::ConvertPositiveOrNegative(float number)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> GenerateIsPositive(0, 1);

    if (GenerateIsPositive(rng)) {
        return number;
    }
    else {
        return -number;
    }
}