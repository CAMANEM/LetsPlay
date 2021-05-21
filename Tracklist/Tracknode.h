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
    void setMatrix(int matrix[9][13]);
    void setNext(Tracknode*);
    Tracknode* getNext();
    Tracknode();

private:
    Tracknode* next = nullptr;

};


#endif //LETSPLAY_TRACKNODE_H
