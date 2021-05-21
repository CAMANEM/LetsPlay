//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_PATHLIST_H
#define LETSPLAY_PATHLIST_H


#include "Pathnode.h"
#include <string.h>
#include <iostream>

class Pathlist {
public:
    void insert(int cell[2]);
    void remove();
    Pathlist();

private:
    Pathnode* head = nullptr;
    Pathnode* tail = nullptr;
    Pathnode* temporal = nullptr;
    int counter = 0;

};


#endif //LETSPLAY_PATHLIST_H
