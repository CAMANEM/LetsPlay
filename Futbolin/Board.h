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
    explicit Board(int squares);
    ~Board();

    std::vector <Line> getBorderLines();
    std::vector <int> getxPos();
    std::vector <int> getyPos();


    void update();
    void A_Star(bool isTurn, int x, int y);
    void render(sf::RenderTarget* target);
private:
    bool isPlayerTurn;
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector <Line> lines;
    std::vector <int> xPos;
    std::vector <int> yPos;
    Squares *Grid = nullptr;

    Squares *start = nullptr;
    Squares *end = nullptr;

    void initBorderLines();
    void initSquaresR(int squares);
    void initSquaresM();
    void initSquaresL(int squares);
    void initGrid();
};

#endif //LETSPLAY_BOARD_H
