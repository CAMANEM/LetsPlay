//
// Created by fernando on 20/5/21.
//

#ifndef LETSPLAY_PATHNODE_H
#define LETSPLAY_PATHNODE_H

class Pathnode {
public:

    /**
     * @brief sets the x and y values associated to the node
     * @param x poss of an specific movement
     * @param y poss of an specific movement
     */
    void setPos(int x, int y);

    /**
     * @brief sets the next node of the current node
     * @param next node pointer
     */
    void setNext(Pathnode* next);

    /**
     * @brief get the next node
     * @return the fallowing node
     */
    Pathnode* getNext();

    /**
     * @brief return the x poss of the node
     * @return x poss of the current node
     */
    int getX();

    /**
     * @brief return the y poss of the node
     * @return y poss of the current node
     */
    int getY();

    /**
     * @brief Constructor
     */
    Pathnode();

private:
    Pathnode* next = nullptr;
    int x;
    int y;
};


#endif //LETSPLAY_PATHNODE_H
