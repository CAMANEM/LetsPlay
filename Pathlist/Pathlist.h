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

    /**
     * @brief inserts the x and y poss related to a possible path position
     * @param x poss related to the matrix
     * @param y poss related to the matrix
     */
    void insert(int x, int y);

    /**
     * @brief removes the last element of the linked list
     */
    void remove();

    /**
     * @brief shows the list content
     */
    void show();

    /**
     * @brief resets the list content
     */
    void reset();

    /**
     * @brief Constructor
     */
    Pathlist();

private:
    int counter = 0;
    Pathnode* head = nullptr;
    Pathnode* tail = nullptr;
    Pathnode* temporal = nullptr;
};


#endif //LETSPLAY_PATHLIST_H
