//
// Created by fernando on 20/5/21.
//

#include "Pathlist.h"

Pathlist::Pathlist() {

}

void Pathlist::insert(int cell[2]) {
    temporal = new Pathnode;
    temporal->setCell(cell);
    if (counter == 0){
        head = temporal;
        tail = temporal;
        temporal->setNext(nullptr);
        counter++;
        std::cout << "Radio Check" << std::endl;


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
    counter--;
    delete temporal;

}