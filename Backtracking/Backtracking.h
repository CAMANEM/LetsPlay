//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_BACKTRACKING_H
#define LETSPLAY_BACKTRACKING_H


#include <iostream>
#include <vector>
#include "../Tracklist/Tracklist.h"
#include "../Pathlist/Pathlist.h"

class Backtracking {
public:

    Tracklist track = Tracklist();
    Pathlist path = Pathlist();
    /**
     * @brief resets the parallel linked lists an the visited matrix
     */
    void reset();

    /**
     * @brief sets the obstacles in to the matrix
     * @param x vector with the x axy values of the obstacles positions
     * @param y vector with the y axy values of the obstacles positions
     */
    void setObstacles(std::vector<int> x, std::vector<int> y, int squares);

    /**
     * @brief gives the path fro an specific position
     * @param i row where the analysis is going to start
     * @param j column where the analysis is going to start
     */
    void road(int i, int j);

    /**
     * @brief Constructor
     */
    Backtracking();
    bool Path(int matrix[9][13], int i, int j);

private:

    void resetFlag();
    bool visited[9][13]= {{true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true},
                          {true, true, true, true, true, true, true, true, true, true, true, true, true}};
    int counter = 0;
    bool founded = false;

    int matrix[9][13] = {
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
    };

};


#endif //LETSPLAY_BACKTRACKING_H
