//
// Created by camanem on 26/5/21.
//

#ifndef LETSPLAY_GENETICPUZZLE_H
#define LETSPLAY_GENETICPUZZLE_H

#include "Chromosome.h"


class GeneticPuzzle {

private:
    int n_generation;
    std::vector<Chromosome*> population;
    int puzzle_size;
    int bits_per_gene;
    int total_bits;

public:
    GeneticPuzzle(int _puzzle_size);

    void firstGeneration(int population_size);

    void newGeneration();

    void showPopulation();
};


#endif //LETSPLAY_GENETICPUZZLE_H
