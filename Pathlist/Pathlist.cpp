//
// Created by fernando on 20/5/21.
//

#include "Pathlist.h"

Pathlist::Pathlist() {

}

void Pathlist::insert(int x, int y) {
    temporal = new Pathnode;
    temporal->setPos(x, y);
    if (counter == 0){
        head = temporal;
        tail = temporal;
        temporal->setNext(nullptr);
        counter++;

    }else{
        tail->setNext(temporal);
        tail = temporal;
        counter++;
    }
}

void Pathlist::remove() {
    temporal = head;
    Pathnode *prev;
    while (temporal->getNext() != nullptr){
        prev =  temporal;
        temporal = temporal->getNext();
    }
    prev->setNext(nullptr);
    tail = prev;
    counter--;
    delete temporal;
}

void Pathlist::show() {
    for (temporal = head; temporal != nullptr; temporal =  temporal->getNext()) {
        std::cout << temporal->getX();
        std::cout << "<->";
        std::cout << temporal->getY() << std::endl;
    }
}

int Pathlist::getX(int position) {
    temporal = head;
    for (int i = 1; i++; i < position) {
        temporal->getNext();
    }
    return temporal->getX();
}

int Pathlist::getY(int position) {
    temporal = head;
    for (int i = 1; i++; i < position) {
        temporal->getNext();
    }
    return temporal->getY();
}

void Pathlist::reset() {
    counter = 0;
    head = nullptr;
    tail = nullptr;
    temporal = nullptr;
}

Pathnode *Pathlist::getHead() {
    return head;
}
