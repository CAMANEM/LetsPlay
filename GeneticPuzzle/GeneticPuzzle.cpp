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

    xml = new XML();
}

void GeneticPuzzle::firstGeneration(int population_size) {

    srand(time(NULL));

    for (int i = 0; i < population_size; i++) {
        Chromosome* chromosome = new Chromosome(&puzzle_size, &total_bits, &bits_per_gene);
        population.push_back(chromosome);
    }
    std::cout << "tamaño poblacion: " << population.size() << std::endl;
//    n_generation = 0;
    sortPopulation( 0, population.size()-1);

    // saves xml
//    std::cout << "puta " << std::endl;
//    std::vector<int> a;
//    a = getPopulation();
//    std::vector<int> jueputafiguerez;
//    jueputafiguerez.push_back(1);
//    jueputafiguerez.push_back(2);
//    xml->Construction(jueputafiguerez);

}

std::vector<int> GeneticPuzzle::getPopulation() {


//
//    std::cout << "wtf" << std::endl;
//    int saved_chromosomes = 0;
//    int total_population = population.size();
//
//    std::vector<int> ipopulation;
//
//    int gen_index = total_bits - 1;
//    int population_index = 0;
//
//    std::bitset<32> num_bits(0);
//    int bitset_index = 31;
//    ipopulation.push_back(bitset_index);
//    while (population_index <  total_population || 10 < ipopulation.size()){
//
//        if (gen_index < 0){
//            std::cout << "hola 1" << std::endl;
//            population_index++;
//            gen_index = total_bits-1;
//        }
//        else if (bitset_index < 0){
//            std::cout << "hola 2" << std::endl;
//            int num = (int)(num_bits.to_ulong());
//            ipopulation.push_back(num);
//            num_bits.reset();
//            bitset_index = 31;
//        }
//        else{
//            std::cout << "hola 3" << std::endl;
//            num_bits.set(bitset_index, population.at(population_index)->getGenes()[gen_index]);
//            gen_index--;
//            bitset_index--;
//        }
//    }
//    std::cout << "tamaño: " << ipopulation.size() << std::endl;
}

std::vector<int> GeneticPuzzle::showPopulation() {

    std::vector<int> pieceslocations(puzzle_size);

    std::cout << "------------>Generación " << n_generation << std::endl;

    int limit = population.size();

//    for (int i = 0; i < limit; i++) {
//
//        std::cout << "gen: " << population.at(i)->getGenes() << std::endl;
//        std::cout << "fitness: " << population.at(i)->getFitness() << std::endl;
//    }
//    std::cout << "Best in ints: " << std::endl;
    return population.at(0)->getPuzzle(&puzzle_size, &total_bits, &bits_per_gene);
}

void GeneticPuzzle::newGeneration() {

    int limit = population.size()/2;
    int limit2 = population.size();
//    std::vector<Chromosome*> new_population;

    std::cout << "pop sise " << population.size() << std::endl;
    int indice = 0;
    for (int i = 0; i < limit; i++) {

        Chromosome* mother = population.at(indice+1);
        Chromosome* chromosome1 = new Chromosome(population.at(indice), mother, &puzzle_size, &total_bits, &bits_per_gene,
                                                true);

        Chromosome* chromosome2 = new Chromosome(population.at(indice), mother, &puzzle_size, &total_bits, &bits_per_gene,
                                                 false);
//        if (chromosome1->getFitness() != 0){
//            new_population.push_back(chromosome1);
//        }
//        if (chromosome2->getFitness() != 0){
//            new_population.push_back(chromosome2);
//        }



        free(population.at(0));
        population.erase(population.begin());
        free(population.at(0));
        population.erase(population.begin());
        population.push_back(chromosome1);
        population.push_back(chromosome2);



    }
//    free(population.at(0));
//    population.erase(population.begin());
//    limit = population.size();
//
//    // SI en la nueva generación no hay suficientes individuos con fitness mayor que cero, se realiza elitismo para
//    // mantener el tamaño de la población
//    for (int i = 0; new_population.size() < limit; i++) {
//        new_population.push_back(population.at(0));
//        population.erase(population.begin());
//    }
//    // Libera la gen anterior
//    for (int i = 0; population.size() != 0; i++) {
//        free(population.at(0));
//        population.erase(population.begin());
//    }
//    population = new_population;
//    sortPopulation(0, population.size()-1);

//    limit = population.size()-1;
//    for (int i = limit; i <= puzzle_size; i--) {
//
//        free(population.at(i));
//        population.erase(population.begin()+i);
////        free(population.at(0));
////        population.erase(population.begin());
//    }
    sortPopulation(0, population.size()-1);
    for (int i = population.size()-1; limit2 < population.size() ; i--) {
//        std::cout << "holaaaa " << std::endl;
        free(population.at(i));
//        population.erase(population.begin()+i);
        population.pop_back();
    }
    n_generation++;

    if (population.at(0)->getFitness() == 0 || 400 < n_generation){
        std::cout << "doomsday" << std::endl;
        int population_size_ = population.size();
        doomsday();
        firstGeneration(population_size_);
    }
    else{
//        getPopulation();
    }
}

void GeneticPuzzle::doomsday() {
    int index = population.size()-1;
    while (!population.empty()){
        free(population.at(index));
        population.pop_back();
        index--;
    }
    std::cout << "new Age" << std::endl;
}

void GeneticPuzzle::sortPopulation(int left, int right) {

    if(left < right) {
        int pivotIndex = partition(left, right);
        sortPopulation(left, pivotIndex - 1);
        sortPopulation(pivotIndex, right);
    }
}

int GeneticPuzzle::partition(int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    Chromosome* pivotValue = population[pivotIndex];
    int i = left, j = right;
    Chromosome* temp;
    while(i <= j) {
        while(population[i]->getFitness() > pivotValue->getFitness()) {
            i++;
        }
        while(population[j]->getFitness() < pivotValue->getFitness()) {
            j--;
        }
        if(i <= j) {
            temp = population[i];
            population[i] = population[j];
            population[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

bool GeneticPuzzle::finished() {
    if (population.at(0)->getFitness() == puzzle_size){
        return true;
    }
    return false;
}
