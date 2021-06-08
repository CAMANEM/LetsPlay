//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_TRACKNODE_H
#define LETSPLAY_TRACKNODE_H

#include <string.h>
#include <iostream>

class Tracknode {
public:
    int matrix[9][13];

    /**
     * @brief sets the matrix associated to the node
     * @param matrix the one is going to be added
     */
    void setMatrix(int matrix[9][13]);

    /**
     * @brief sets the next node of the current node
     * @param next node pointer
     */
    void setNext(Tracknode* next);

    /**
     * @brief get the next node
     * @return the fallowing node
     */
    Tracknode* getNext();

    /**
     * @brief Constructor
     */
    Tracknode();

private:
    Tracknode* next = nullptr;
};


#endif //LETSPLAY_TRACKNODE_H
