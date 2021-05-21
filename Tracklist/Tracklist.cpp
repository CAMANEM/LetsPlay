//
// Created by fernando on 20/5/21.
//

#include "Tracklist.h"

Tracklist::Tracklist() {

}

void Tracklist::insert(int matrix[9][13]) {
    temporal = new Tracknode;
    temporal->setMatrix(matrix);
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

void Tracklist::remove() {

    temporal = head;
    Tracknode *prev;
    while (temporal->getNext() != nullptr){
        prev =  temporal;
        temporal = temporal->getNext();
    }
    prev->setNext(nullptr);
    counter--;
    delete temporal;

}