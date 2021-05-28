//
// Created by marco on 5/25/21.
//

#include "Board.h"
#include <cstdlib>
#include <ctime>

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

void Board::render(sf::RenderTarget* target){
    //target->draw(sprite);

    for (auto i : lines)
    {
        target->draw(i);
    }
}