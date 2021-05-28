//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_PATHNODE_H
#define LETSPLAY_PATHNODE_H


class Pathnode {
public:

    void setPos(int x, int y);
    void setNext(Pathnode* next);
    Pathnode* getNext();
    int getX();
    int getY();
    Pathnode();

private:
    Pathnode* next = nullptr;
    int x;
    int y;
};


#endif //LETSPLAY_PATHNODE_H
