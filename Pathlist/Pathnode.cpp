//
// Created by fernando on 20/5/21.
//

#include "Pathnode.h"

Pathnode::Pathnode() {

}

void Pathnode::setPos(int x , int y ){
    Pathnode::x = x;
    Pathnode::y = y;
}

Pathnode *Pathnode::getNext() {
    return next;
}

void Pathnode::setNext(Pathnode * next) {
    Pathnode::next =  next;

}

int Pathnode::getX() {
    return x;
}

int Pathnode::getY() {
    return y;
}
