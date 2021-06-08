//
// Created by camanem on 26/5/21.
//

#include "GeneticPuzzle.h"
#include <bits/stdc++.h>
#include <XML.h>
#include <boost/algorithm/string.hpp>

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
    n_generation = 0;
    sortPopulation( 0, population.size()-1);


    std::string paXML;
    std::vector<int> elVector = showPopulation();
    for (int i = 0; i < elVector.size(); i++) {
        paXML.append(std::to_string(elVector.at(i)));
        paXML.append(",");
    }
    paXML.pop_back();
    xml.Construction(paXML);

//    // getter
//    std::vector<std::string> result;
//    boost::split(result, xml.Population(0), boost::is_any_of(","));
//    std::vector<int> genbest;
//    for (int i = 0; i < result.size(); i++) {
//        genbest.push_back(std::stoi(result[i]));
//        std::cout << result[i] << std::endl;
//        std::cout << genbest.at(i) << std::endl;
//    }

//    std::cout << xml.Population(0) << std::endl;

//    std::cout << xml.Population(1) << std::endl;

//    xml.Construction(population.at(0)->bits_to_string(&total_bits));
//    getFromFile(0);


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
        doomsday();
        firstGeneration(200);
    }

//    xml.Construction(population.at(0)->bits_to_string(&total_bits));

    std::string paXML;
    std::vector<int> elVector = showPopulation();
    for (int i = 0; i < elVector.size(); i++) {
        paXML.append(std::to_string(elVector.at(i)));
        paXML.append(",");
    }
    paXML.pop_back();
    xml.Construction(paXML);
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

std::vector<int> GeneticPuzzle::getFromFile(int n_generation) {
    boost::dynamic_bitset<> genes;
    genes.resize(total_bits);
    int genesIndex = total_bits-1;
    std::string best = xml.Population(n_generation);
    int index = best.size() - 1;
    std::string num;

    while (!best.empty()){
        std::string comparator = std::to_string(best[index]);
        if (std::strcmp(&best.at(index), ",")){
            std::bitset<32> newNUM(std::stoi(comparator));
            for (int i = 31; 0 <= i; i--) {
//                std::cout << "aaaaaa" << std::endl;
//                std::cout << "entró" << std::endl;
                genes.set(genesIndex, newNUM[i]);
                genesIndex--;
            }
            best.erase(index, 1);
            num = "";
            index--;
        }
        else {
            std::cout << "aaaaaa" << num << std::endl;
            num+= best[index];

            best.erase(index, 1);
            index--;
        }
    }
    std::cout << "genescnvrt: " << genes << std::endl;

    std::vector<int> puzzle_order;
    puzzle_order.push_back(1);
    return puzzle_order;
}

std::vector<int> GeneticPuzzle::getFromFile2() {
    std::vector<std::string> result;
    boost::split(result, xml.Population(0), boost::is_any_of(","));
    std::vector<int> genbest;
    for (int i = 0; i < result.size(); i++) {
//        std::cout << result[i] << std::endl;
        genbest.push_back(std::stoi(result[i]));
        std::cout << genbest.at(i) << std::endl;
    }
    return genbest;
}
