//
// Created by marco on 5/25/21.
//

#ifndef LETSPLAY_BOARD_H
#define LETSPLAY_BOARD_H
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Line.h"
#include "Squares.h"

class Board
{
public:

    /*!
     * @brief Constructor para el tablero.
     * @param squares Cantidad de obstaculos a dibujar.
     */
    explicit Board(int squares);

    /*!
     * @brief Destructor para la clase.
     */
    ~Board();

    /*!
     * @brief Lineas existentes con las que la bola puede colisionar.
     * @return Vector de lineas.
     */
    std::vector <Line> getBorderLines();

    /*!
     * @brief Getter para las coordenadas x donde has obstaculos.
     * @return Casillas x.
     */
    std::vector <int> getxPos();

    /*!
     * @brief Getter para las coordenadas y donde has obstaculos.
     * @return Casillas y.
     */
    std::vector <int> getyPos();

    /*!
     * @brief Updater.
     */
    void update();

    /*!
     * @brief Funcion que se encarga de resover el pathfinding usando A*
     * @param isTurn Bool correspondiente a si hay que resolver o no el grid.
     * @param x Posicion x inicial.
     * @param y Posicion y inicial.
     */
    void A_Star(bool isTurn, int x, int y);

    /*!
     * @brief Funcion que se encarga de dibujar en pantalla el tablero.
     * @param target Ventana sobre la cual trabajar.
     */
    void render(sf::RenderTarget* target);

private:
    std::vector <int> xPos;
    std::vector <int> yPos;
    bool isPlayerTurn;
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector <Line> lines;
    Squares *Grid = nullptr;

    Squares *start = nullptr;
    Squares *end = nullptr;

    /*!
     * @brief Inicializador para las lineas exteriores del tablero.
     */
    void initBorderLines();

    /*!
     * @brief Inicializador para los obstaculos en la parte derecha del tablero.
     * @param squares Cantidad de obstaculos.
     */
    void initSquaresR(int squares);

    /*!
     * @brief Inicializador para el obstaculo en medio del tablero.
     */
    void initSquaresM();

    /*!
     * @brief Inicializador para los obstaculos en la parte izquierda del tablero.
     * @param squares Cantidad de obstaculos.
     */
    void initSquaresL(int squares);

    /*!
     * @brief Inicializador para la cuadricula con la que trabaja A*
     */
    void initGrid();
};

#endif //LETSPLAY_BOARD_H
