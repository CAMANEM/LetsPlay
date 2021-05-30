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


    bool Path(int matrix[9][13], int i, int j);
    void reset();
    void resetFlag();
    void setObstacles(std::vector<int> x, std::vector<int> y);
    void road(int i, int j);
    Backtracking();

private:
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
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
    };

};


#endif //LETSPLAY_BACKTRACKING_H
