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

    /**
     * @brief Ordena el vector con la poplación de forma descendente mediante QuickSort
     * @param left indice del límite izquierdo de la lista o fracción de la lista a ordenar
     * @param right indice del límite derecho de la lista o fracción de la lista a ordenar
     */
    void sortPopulation(int left, int right);

    /**
     * @brief Es un método auxiliar de sortPopulation. recorre la lista según los indices dados y ordena sus valores
     * de forma descendente
     * @param left indice del límite izquierdo de la fracción de la lista a ordenar
     * @param right indice del límite derecho de la fracción de la lista a ordenar
     * @return indice del pivote a partir del cual ya se ordenó la lista
     */
    int partition(int left, int right);

public:
    GeneticPuzzle(int _puzzle_size);

    void firstGeneration(int population_size);

    void newGeneration();

    std::vector<int> showPopulation();

    bool finished();
};


#endif //LETSPLAY_GENETICPUZZLE_H
