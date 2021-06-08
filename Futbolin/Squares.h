//
// Created by marco on 6/6/21.
//

#ifndef LETSPLAY_SQUARES_H
#define LETSPLAY_SQUARES_H


#include <vector>

class Squares {
public:
    bool isObstacle = false;
    bool beenVisited = false;
    float Goal; //distancia total hacia la meta
    float LocalGoal; //distancia a la meta si se toma otro camino
    int x;
    int y;
    std::vector<Squares*> Neighbours;
    Squares* Previous;
};


#endif //LETSPLAY_SQUARES_H
