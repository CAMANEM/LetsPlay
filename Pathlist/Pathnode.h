//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_PATHNODE_H
#define LETSPLAY_PATHNODE_H


class Pathnode {
public:
    int cell[2];
    void setCell(int cell[2]);
    void setNext(Pathnode*);
    Pathnode* getNext();
    Pathnode();

private:
    Pathnode* next = nullptr;
};


#endif //LETSPLAY_PATHNODE_H
