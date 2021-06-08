//
// Created by marco on 5/25/21.
//

#ifndef LETSPLAY_GAME_H
#define LETSPLAY_GAME_H
#include "Line.h"
#include "Board.h"
#include "Ball.h"
#include <SFML/Window/VideoMode.hpp>
#include "../Backtracking/Backtracking.h"

class Game {
public:
    /*!
     * @brief Constructor para el juego
     * @param squares Numero de obstaculos en pantalla
     * @param score Numero de goles para victoria
     */
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

    /*!
     * @brief Funcion encargaca de detectar colision entre bola y linea
     * @param circle Bola a comparar
     * @param line Linea a comparar
     */
    void collisionCircleLine(Ball* circle, Line* line);

    /*!
     * @brief Funcion que actualiza la barra de poder
     */
    void updateDirectionLine();

    /*!
     * @brief Actaulizador de todas las colisiones posibles
     */
    void updateAllCollisions();

    /*!
     * @brief Actualizador de la logica del juego
     */
    void updateGameLogic();

    /*!
     * @brief Funcion encargada de verificar en que casilla esta la bola
     * @param x Casilla x
     * @param y Casilla y
     */
    void checkBallSquare(float x, float y);

private:
    sf::RectangleShape LeftGoal;
    sf::RectangleShape RightGoal;
    int max_score;
    int player_score;
    int rival_score;
    int x_ball_position = -1;
    int y_ball_position = -1;

    Backtracking backtracking;

    bool secondFlag = true;

    sf::Vector2f m_mouse;
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event event;

    /*!
     * @brief Inicilizador de la ventana
     */
    void initWindow();

    /*!
     * @brief Inicializador de la logica del juego
     * @param squares Cuadrados a dibujar en pantalla
     * @param score Puntaje a dibujar en pantalla
     */
    void initGame(int squares, int score);

};


#endif //LETSPLAY_GAME_H
