#include <iostream>
#include "GUI/Main_Window.h"
#include "GeneticPuzzle/GeneticPuzzle.h"
#include <bits/stdc++.h>
int main() {

//    Main_Window* mainWindow = new Main_Window();
//    mainWindow->Run();

//    GeneticPuzzle* geneticPuzzle = new GeneticPuzzle(5);
//    std::bitset<32> bitsets(0);
//    std::cout << "int:   ";
//    for (int i = 0; i < 5; i++) {
//        std::cout << bitsets;
//    }

    GeneticPuzzle* geneticPuzzle = new GeneticPuzzle(9);
    geneticPuzzle->firstGeneration(4);
    geneticPuzzle->newGeneration();
    geneticPuzzle->showPopulation();
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