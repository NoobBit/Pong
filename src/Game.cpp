#include "headers\Game.h"

Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string SCREEN_TITLE, int FPS)
{
    this->SCREEN_WIDTH = SCREEN_WIDTH;
    this->SCREEN_HEIGHT = SCREEN_HEIGHT;
    this->SCREEN_TITLE = SCREEN_TITLE;
    this->FPS = FPS;

    this->Init();
}

void Game::Init()
{
    InitWindow(this->SCREEN_WIDTH, this->SCREEN_HEIGHT, this->SCREEN_TITLE.c_str());
    SetTargetFPS(this->FPS);
}

void Game::Loop()
{
    Ball ball(this->SCREEN_WIDTH / 2 - (20 / 2), this->SCREEN_HEIGHT / 2 - (20 / 2), 20, 2, 2, WHITE);
    Player player1(0, this->SCREEN_HEIGHT / 2 - (150 / 2), 20, 100, 2.5, KEY_W, KEY_S, WHITE);
    Player player2(SCREEN_WIDTH - 20, this->SCREEN_HEIGHT / 2 - (150 / 2), 20, 100, 2.5, KEY_UP, KEY_DOWN, WHITE);

    while (!WindowShouldClose())
    {
        ball.Update();
        player1.Update();
        player2.Update();

        this->sineBounce += .1;

        if (CheckCollisionRecs(ball.rect, player1.paddleRect) || CheckCollisionRecs(ball.rect, player2.paddleRect))
        {
            ball.BounceX();
        }

        if (ball.rect.y <= 0 || ball.rect.y >= SCREEN_HEIGHT - 20)
        {
            ball.BounceY();
        }

        if (ball.rect.x < -ball.rect.width)
        {
            this->ScorePoint(player2, 1);
            this->ResetPositions(player1, player2, ball);
        }
        if (ball.rect.x > SCREEN_WIDTH)
        {
            this->ScorePoint(player1, 1);
            this->ResetPositions(player1, player2, ball);
        }
        BeginDrawing();
            ClearBackground(BLACK);
            this->DrawBackUI();

            ball.Draw();
            player1.Draw();
            player2.Draw();

            this->DrawFrontUI(player1, player2);
        EndDrawing();
    }
}

void Game::ScorePoint(Player &scoredPlayer, int scoreAmount)
{
    scoredPlayer.SetScore(scoredPlayer.GetScore() + scoreAmount);
}

void Game::ResetPositions(Player &player1, Player &player2, Ball &ball)
{
    player1.ResetPaddlePosition();
    player2.ResetPaddlePosition();
    ball.Reset();
}

void Game::DrawFrontUI(Player &player1, Player &player2)
{
    int scoreTextFontSize = 70;
    int scoreTextOffset = 60;

    DrawText(std::to_string(player1.GetScore()).c_str(), 
        (SCREEN_WIDTH / 2 - ((std::to_string(player1.GetScore()).length() * scoreTextFontSize) / 2)) - scoreTextOffset, 
        60 + (sin(sineBounce) * 2), scoreTextFontSize, GRAY
    );
    DrawText(std::to_string(player2.GetScore()).c_str(), 
        (SCREEN_WIDTH / 2 - ((std::to_string(player2.GetScore()).length() * scoreTextFontSize) / 2)) + scoreTextOffset + 40, 
        60 + (sin(sineBounce + 3) * 2), scoreTextFontSize, GRAY
    );
}

void Game::DrawBackUI()
{
    DrawLineEx(
        Vector2{static_cast<float>(SCREEN_WIDTH / 2), 0}, 
        Vector2{static_cast<float>(SCREEN_WIDTH / 2), static_cast<float>(SCREEN_HEIGHT) - 40}, 
        8, LIGHTGRAY
    );
    DrawText("NoobBit", 
        SCREEN_WIDTH / 2 - ((7 * 20) / 4), 
        SCREEN_HEIGHT - 30 + sin(sineBounce - .05), 
        20, WHITE
    );
}

void Game::Close()
{
    CloseWindow();
    CloseAudioDevice();
}