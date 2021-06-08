//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_TRACKLIST_H
#define LETSPLAY_TRACKLIST_H

#include "Tracknode.h"
#include <string.h>

class Tracklist {
public:

    /**
     * @brief inserts a matrix with the actual state of if,
     * the one could be use by the Backtracking
     * @param matrix after a movement
     */
    void insert(int matrix[9][13]);

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
    Tracknode* tail = nullptr;

    /**
     * @brief Constructor
     */
    Tracklist();

private:
    Tracknode* head = nullptr;
    Tracknode* temporal = nullptr;
    int counter = 0;
};


#endif //LETSPLAY_TRACKLIST_H
