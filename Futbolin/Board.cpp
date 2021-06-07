//
// Created by marco on 5/25/21.
//

#include "Board.h"
#include <cstdlib>
#include <ctime>
#include "Squares.h"
#include "limits"
#include <cmath>
#include <math.h>
#include <list>

Board::Board(int squares){
    initBorderLines();
    srand(time(NULL));
    if (squares%2 == 0){
        initSquaresL(squares/2);
        initSquaresR(squares/2);
    }else{
        initSquaresL(squares/2);
        initSquaresM();
        initSquaresR(squares/2);
    }
    initGrid();
}

Board::~Board(){
    lines.clear();
}

void Board::initBorderLines(){
    Line lineTop(102.5f, 69.5f, 1397.5f, 69.5f);
    lines.push_back(lineTop);

    Line lineRight(1397.5f, 69.5f, 1397.5f, 733.5f);
    lines.push_back(lineRight);

    Line lineDown(1397.5f, 733.5f, 102.5f, 733.5f);
    lines.push_back(lineDown);

    Line lineLeft(102.5f, 733.5f, 102.5f, 69.5f);
    lines.push_back(lineLeft);
}

void Board::initSquaresL(int squares){
    std::vector<int> xPosList {1,2,3,4,5};
    std::vector<int> yPosList {0,1,2,3,4,5,6,7,8};
    int i = 0;
    while(i < squares){
        int xIndex = rand() % xPosList.size();
        int yIndex = rand() % yPosList.size();
        int Xselected = xPosList[xIndex];
        int Yselected = yPosList[yIndex];
        xPos.push_back(Xselected);
        yPos.push_back(Yselected);

        Line lineTop(99.615384f*Xselected+102.5f, 73.7777777f*Yselected+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*Yselected+69.5f);
        lines.push_back(lineTop);

        Line lineRight(99.615384f*(Xselected+1)+102.5f, 73.7777777f*Yselected+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*(Yselected+1)+69.5f);
        lines.push_back(lineRight);

        Line lineDown(99.615384f*Xselected+102.5f, 73.7777777f*(Yselected+1)+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*(Yselected+1)+69.5f);
        lines.push_back(lineDown);

        Line lineLeft(99.615384f*Xselected+102.5f, 73.7777777f*(Yselected+1)+69.5f, 99.615384f*Xselected+102.5f, 73.7777777f*Yselected+69.5f);
        lines.push_back(lineLeft);

        //xPosList.erase(std::remove(xPosList.begin(), xPosList.end(), Xselected), xPosList.end());
        yPosList.erase(std::remove(yPosList.begin(), yPosList.end(), Yselected), yPosList.end());
        i++;
    }
}

void Board::initSquaresR(int squares){
    std::vector<int> xPosList {7,8,9,10,11};
    std::vector<int> yPosList {0,1,2,3,4,5,6,7,8};
    int i = 0;
    while(i < squares){
        int xIndex = rand() % xPosList.size();
        int yIndex = rand() % yPosList.size();
        int Xselected = xPosList[xIndex];
        int Yselected = yPosList[yIndex];
        xPos.push_back(Xselected);
        yPos.push_back(Yselected);

        Line lineTop(99.615384f*Xselected+102.5f, 73.7777777f*Yselected+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*Yselected+69.5f);
        lines.push_back(lineTop);

        Line lineRight(99.615384f*(Xselected+1)+102.5f, 73.7777777f*Yselected+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*(Yselected+1)+69.5f);
        lines.push_back(lineRight);

        Line lineDown(99.615384f*Xselected+102.5f, 73.7777777f*(Yselected+1)+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*(Yselected+1)+69.5f);
        lines.push_back(lineDown);

        Line lineLeft(99.615384f*Xselected+102.5f, 73.7777777f*(Yselected+1)+69.5f, 99.615384f*Xselected+102.5f, 73.7777777f*Yselected+69.5f);
        lines.push_back(lineLeft);

        //xPosList.erase(std::remove(xPosList.begin(), xPosList.end(), Xselected), xPosList.end());
        yPosList.erase(std::remove(yPosList.begin(), yPosList.end(), Yselected), yPosList.end());
        i++;
    }
}

void Board::initSquaresM(){
    int Xselected = 6;
    int Yselected = rand() % 9;
    if (Yselected == 4){
        Yselected++;
    }
    xPos.push_back(Xselected);
    yPos.push_back(Yselected);

    Line lineTop(99.615384f*Xselected+102.5f, 73.7777777f*Yselected+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*Yselected+69.5f);
    lines.push_back(lineTop);

    Line lineRight(99.615384f*(Xselected+1)+102.5f, 73.7777777f*Yselected+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*(Yselected+1)+69.5f);
    lines.push_back(lineRight);

    Line lineDown(99.615384f*Xselected+102.5f, 73.7777777f*(Yselected+1)+69.5f, 99.615384f*(Xselected+1)+102.5f, 73.7777777f*(Yselected+1)+69.5f);
    lines.push_back(lineDown);

    Line lineLeft(99.615384f*Xselected+102.5f, 73.7777777f*(Yselected+1)+69.5f, 99.615384f*Xselected+102.5f, 73.7777777f*Yselected+69.5f);
    lines.push_back(lineLeft);
}

void Board::initGrid() {
    Grid = new Squares[13*9];

    for (int x = 0; x < 13; x++){
        for (int y = 0; y < 9; y++){
            Grid[y * 13 + x].x = x; // ...because we give each node its own coordinates
            Grid[y * 13 + x].y = y;
            Grid[y * 13 + x].isObstacle = false;
            Grid[y * 13 + x].Previous = nullptr;
            Grid[y * 13 + x].beenVisited = false;

            if (y > 0) {
                Grid[y * 13 + x].Neighbours.push_back(&Grid[(y - 1) * 13 + (x + 0)]);
            }
            if (y < 9 - 1) {
                Grid[y * 13 + x].Neighbours.push_back(&Grid[(y + 1) * 13 + (x + 0)]);
            }
            if (x > 0) {
                Grid[y * 13 + x].Neighbours.push_back(&Grid[(y + 0) * 13 + (x - 1)]);
            }
            if (x < 13 - 1) {
                Grid[y * 13 + x].Neighbours.push_back(&Grid[(y + 0) * 13 + (x + 1)]);
            }
        }
    }

    start = &Grid[4 * 13 + 6];
    end = &Grid[4 * 13 + 0];


    for (int i = 0; i < xPos.size(); i++){
        Grid[yPos[i] * 13 + xPos[i]].isObstacle = true;
    }
}


std::vector<Line> Board::getBorderLines(){
    return lines;
}

std::vector<int> Board::getxPos() {
    return xPos;
}

std::vector<int> Board::getyPos() {
    return yPos;
}



void Board::update(){

}

void Board::A_Star() {
    for (int x = 0; x < 13; x++){
        for (int y = 0; y < 9; y++){
            Grid[y*13 + x].beenVisited = false;
            Grid[y*13 + x].Goal = std::numeric_limits<int>::max();
            Grid[y*13 + x].LocalGoal = std::numeric_limits<int>::max();
            Grid[y*13 + x].Previous = nullptr;	// No parents
        }
    }

    auto distance = [](Squares* a, Squares* b) // For convenience
    {
        return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
    };

    auto heuristic = [distance](Squares* a, Squares* b) // So we can experiment with heuristic
    {
        return distance(a, b);
    };

    Squares *nodeCurrent = start;
    start->LocalGoal = 0.0f;
    start->Goal = heuristic(start, end);

    std::list<Squares*> listNotTestedNodes;
    listNotTestedNodes.push_back(start);

    while(!listNotTestedNodes.empty()){
        listNotTestedNodes.sort([](const Squares* lhs, const Squares* rhs){ return lhs->Goal < rhs->Goal; } );
        while(!listNotTestedNodes.empty() && listNotTestedNodes.front()->beenVisited){
            listNotTestedNodes.pop_front();
        } if (listNotTestedNodes.empty()) {
            break;
        }

        nodeCurrent = listNotTestedNodes.front();
        nodeCurrent->beenVisited = true;

        for (auto nodeNeighbour : nodeCurrent->Neighbours){
            if (!nodeNeighbour->beenVisited && nodeNeighbour->isObstacle == 0) {
                listNotTestedNodes.push_back(nodeNeighbour);
            }

            float fPossiblyLowerGoal = nodeCurrent->LocalGoal + distance(nodeCurrent, nodeNeighbour);

            if (fPossiblyLowerGoal < nodeNeighbour->LocalGoal){
                nodeNeighbour->Previous = nodeCurrent;
                nodeNeighbour->LocalGoal = fPossiblyLowerGoal;

                nodeNeighbour->Goal = nodeNeighbour->LocalGoal + heuristic(nodeNeighbour, end);
            }
        }
    }
}

void Board::render(sf::RenderTarget* target){
    //target->draw(sprite);
    A_Star();
//    for (int x = 0; x < 13; x++){
//        for (int y = 0; y < 9; y++){
//            sf::RectangleShape square(sf::Vector2f(59.615384f,38.7777777f));
//            square.setPosition(125.5f +  (x * 50) + (x * 49.5f), 86.94f +  (y * 50) + (y * 23.44f));
//
//
//            if (&Grid[y * 13 + x] == start){
//                square.setFillColor(sf::Color(0, 220, 0));
//            } else if (&Grid[y * 13 + x] == end){
//                square.setFillColor(sf::Color(0, 0, 0));
//            }else if (!Grid[y * 13 + x].isObstacle){
//                square.setFillColor(sf::Color(254, 154, 39));
//            }else {
//                square.setFillColor(sf::Color(232, 220, 0));
//            }
//
//
//            target->draw(square);
//        }
//    }

    Squares *temp = end;
    while (temp->Previous != nullptr){
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(temp->x*99.615384f + 73.7777777f/2 + 116.5f, temp->y*73.7777777f + 99.615384f/2 + 55.5f)),
                sf::Vertex(sf::Vector2f(temp->Previous->x*99.615384f + 73.7777777f/2 + 116.5f, temp->Previous->y*73.7777777f + 99.615384f/2 + 55.5f))
        };
        target->draw(line, 2, sf::Lines);

        temp = temp->Previous;
    }
    for (auto i : lines)
    {
        target->draw(i);
    }
}