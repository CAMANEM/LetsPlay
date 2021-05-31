#include <iostream>
#include "GUI/Main_Window.h"
#include "GeneticPuzzle/GeneticPuzzle.h"
#include <bits/stdc++.h>
int main() {

    Main_Window* mainWindow = new Main_Window();
    mainWindow->Run();

//    GeneticPuzzle* geneticPuzzle = new GeneticPuzzle(5);
//    std::bitset<32> bitsets(0);
//    std::cout << "int:   ";
//    for (int i = 0; i < 5; i++) {
//        std::cout << bitsets;
//    }

//    GeneticPuzzle* geneticPuzzle = new GeneticPuzzle(7);
//    geneticPuzzle->firstGeneration(15);
//
//    geneticPuzzle->showPopulation();
//    for (int i = 0; i < 60; i++) {
//        geneticPuzzle->newGeneration();
//        std::vector<int> a = geneticPuzzle->showPopulation();
//        for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++) {
//            std::cout << *it;
//        }
//        std::cout << "-------" << std::endl;
//        unsigned int microseconds;
//        microseconds = 1000000;
//        usleep(microseconds);
//    }
    return 0;
}

/**
* Pa que vea la diferencia en uso de memoria
 *
 * GeneticPuzzle* geneticPuzzle = new GeneticPuzzle(5);
    std::bitset<32> bitsets(0);
    std::cout << "int:   ";
    for (int i = 0; i < 5; i++) {
        std::cout << bitsets;
    }
*/