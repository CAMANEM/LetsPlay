//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_BACKTRACKING_H
#define LETSPLAY_BACKTRACKING_H


#include <iostream>
#include "../Tracklist/Tracklist.h"
#include "../Pathlist/Pathlist.h"

class Backtracking {
public:


    bool Path(int matrix[9][13], int i, int j);
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

};


#endif //LETSPLAY_BACKTRACKING_H
