//
// Created by marco on 5/25/21.
//

#ifndef LETSPLAY_GAME_H
#define LETSPLAY_GAME_H
#include "Line.h"
#include "Board.h"
#include "Ball.h"
#include <SFML/Window/VideoMode.hpp>

class Game {
public:
    Game(int squares, int score);
    Board* board;
    Line* direction;
    void update();
    void render();
    void pollEvents();

    Ball* black;
    Ball* draggedBall;
    bool dragged;
    bool move;
    bool isPlayerTurn = true;
    sf::Clock clock;


    void collisionCircleLine(Ball* circle, Line* line);
    void updateDirectionLine();
    void updateAllCollisions();
    //void collisionCircles(Ball* ball1, Ball* ball2);
    void updateGameLogic();

    void checkBallSquare(float x, float y);

private:
    sf::RectangleShape LeftGoal;
    sf::RectangleShape RightGoal;
    int max_score;
    int player_score;
    int rival_score;
    int x_ball_position = -1;
    int y_ball_position = -1;

    sf::Vector2f m_mouse;
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event event;
    void initWindow();
    void initGame(int squares, int score);

};


#endif //LETSPLAY_GAME_H
