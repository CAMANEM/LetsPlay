//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_TRACKLIST_H
#define LETSPLAY_TRACKLIST_H

#include "Tracknode.h"
#include <string.h>


class Tracklist {
public:
    void insert(int matrix[9][13]);
    void remove();
    void show();
    void reset();
    Tracknode* tail = nullptr;
    Tracklist();

private:
    Tracknode* head = nullptr;

    Tracknode* temporal = nullptr;
    int counter = 0;

};


#endif //LETSPLAY_TRACKLIST_H
