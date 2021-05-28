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
    tail = prev;
    counter--;
    delete temporal;

}
void Tracklist::show() {
    for(int i = 0; i<9; i++){
        for (int j = 0; j < 13; ++j) {
            std::cout << tail->matrix[i][j];
        }
        std::cout << std::endl;
    }
}