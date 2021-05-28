//
// Created by camanem on 26/5/21.
//

#include "GeneticPuzzle.h"
#include <bits/stdc++.h>



GeneticPuzzle::GeneticPuzzle(const int _puzzle_size) {

    GeneticPuzzle::puzzle_size = _puzzle_size;
    GeneticPuzzle::bits_per_gene = (int)(log2(puzzle_size))+1;
    GeneticPuzzle::total_bits = bits_per_gene * puzzle_size;

    std::cout << "puzzle size: " << puzzle_size << std::endl;
    std::cout << "total bits: " << total_bits << std::endl;
    std::cout << "bits per gene: " << bits_per_gene << std::endl;
}

void GeneticPuzzle::firstGeneration(int population_size) {

    srand(time(NULL));

    for (int i = 0; i < population_size; i++) {
        Chromosome* chromosome = new Chromosome(&puzzle_size, &total_bits, &bits_per_gene);
        population.push_back(chromosome);
    }
    std::cout << "tamaño poblacion: " << population.size() << std::endl;
}

void GeneticPuzzle::showPopulation() {

    int limit = population.size();

    for (int i = 0; i < limit; i++) {

        std::cout << "gen: " << population.at(i)->getGenes() << std::endl;
        std::cout << "fitness: " << population.at(i)->getFitness() << std::endl;
    }
}

void GeneticPuzzle::newGeneration() {

    Chromosome* chromosome = new Chromosome(population.at(0), population.at(1), &puzzle_size, &total_bits, &bits_per_gene,
                                            true);
    population.push_back(chromosome);
}
