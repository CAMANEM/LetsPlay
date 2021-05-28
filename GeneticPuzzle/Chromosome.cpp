//
// Created by camanem on 26/5/21.
//

#include "Chromosome.h"

int Chromosome::getFitness() const {
    return fitness;
}

void Chromosome::setFitness(const int* _puzzle_size, const int* _total_bits, const int* _bits_per_gene) {

    int correct_gen = 0;
    // streak mientras todos los genes leidos son correctos
    bool streak = true;

    int bit_position = *_total_bits-1;
    bool no_errors = true;

    std::vector<int> used_genes;

    int cell;

    while (0 <= bit_position && no_errors){

        std::bitset<32> reading(0);
        // Necesario para conversion de bits a int
        for (int i = *_bits_per_gene-1; 0 <= i; i--) {
            reading.set(i, genes[bit_position]);
            bit_position--;
        }
        cell = (int)(reading.to_ulong());

        // Si el cromosoma repite genes o un gen es invalido.
        if (std::find(used_genes.begin(), used_genes.end(), cell) != used_genes.end() ||  *_puzzle_size-1 < cell){
            std::cout << "Error" << std::endl;
            no_errors = false;
            fitness = -1;
        }
        else if (cell == correct_gen){
            if (streak){
                fitness += 2;
            }
            else {
                fitness++;
            }
        }
        else{
            streak = false;
        }
        correct_gen++;
        used_genes.push_back(cell);
    }
}


// Está tirando muchos errores
int Chromosome::getCrossoverPoint(Chromosome *father, const int* _puzzle_size, const int *_total_bits, const int *_bits_per_gene) {

    int correct_gen = 0;
    int bit_position = *_total_bits-1;
    int cell;

    for (int i = 0; i < *_puzzle_size; i++) {

        std::bitset<32> reading(0);

        for (int j = *_bits_per_gene-1; 0 <= j; j--) {

            reading.set(j, father->getGenes()[bit_position]);
            bit_position--;

        }
        cell = (int)(reading.to_ulong());

        if (cell != correct_gen){
            return bit_position+*_bits_per_gene;
        }
        correct_gen++;
    }
    return bit_position;
}

Chromosome::Chromosome(Chromosome *father, Chromosome *mother, const int *_puzzle_size, const int *_total_bits,
                       const int *_bits_per_gene, bool firstChild) {

    genes.resize(*_total_bits);
    int crossover_point = getCrossoverPoint(father, _puzzle_size, _total_bits, _bits_per_gene);
    genes = father->getGenes();

    boost::dynamic_bitset<> mother_genes(*_total_bits);
    mother_genes = mother->getGenes();

    for (int i = crossover_point; 0 <= i; i--) {

        genes.set(i, mother_genes[i]);
    }
    setFitness(_puzzle_size, _total_bits, _bits_per_gene);
}

Chromosome::Chromosome(const int *_puzzle_size, const int *_total_bits, const int *_bits_per_gene) {

    genes.resize(*_total_bits);
    int bit_position = *_total_bits-1;
    std::vector<int> values;

    for (int i = 0; i < *_puzzle_size; i++) {
        values.push_back(i);
    }

    // Recorre cada gen(rango de bits) y elige un numero aleatorio para cada gen
    for (int i = 0; i < *_puzzle_size; i++) {

        std::bitset<32> binary_number(randInt(&values) );

        // Escribe el numero aleatorio en el debido gen. Se va escribiendo de derecha a izquierda,
        for (int j = *_bits_per_gene-1; 0 <= j; j--) {

            genes.set(bit_position, binary_number[j]);
            bit_position--;
        }
    }
    setFitness(_puzzle_size, _total_bits, _bits_per_gene);
}

int Chromosome::randInt(std::vector<int>* _values) {

    int random_number =  rand() % _values->size();
    int random_value = _values->at(random_number);
    _values->erase(_values->begin()+random_number);
    return random_value;
}

const boost::dynamic_bitset<> &Chromosome::getGenes() const {
    return genes;
}


/**
 * bitset a int
 *
 * int a = (int)(bitset.to_ulong());
*/