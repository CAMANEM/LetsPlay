//
// Created by fernando on 20/5/21.
//

#include "Tracknode.h"
#include <iostream>


using namespace std;

Tracknode::Tracknode() {

}

void Tracknode::setNext(Tracknode * next) {
    Tracknode::next = next;
}

Tracknode *Tracknode::getNext() {

    return next;
}

void Tracknode::setMatrix(int _matrix[9][13]) {
    memcpy(matrix, _matrix, sizeof(int)*9*13);


}
