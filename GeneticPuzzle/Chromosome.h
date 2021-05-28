//
// Created by camanem on 26/5/21.
//

#ifndef LETSPLAY_CHROMOSOME_H
#define LETSPLAY_CHROMOSOME_H

#include <bits/stdc++.h>

#include<boost/dynamic_bitset.hpp>

class Chromosome {

private:
    int fitness = 0;
    boost::dynamic_bitset<> genes;

    /**
     * @brief retorna un número aleatorio que se toma de una lista con valores validos
     * @param _values lista de numeros validos por colocar
     * @return random_value un numero aleatorio no utilizado antes
     */
    int randInt(std::vector<int>* _values);

    /**
     * @brief Calcula en fitness del cromosoma o individuo
     * @param _puzzle_size numero de piezas que tiene el puzzle
     * @param _total_bits numero de bits totales que utiliza el cromosoma
     * @param _bits_per_gene numero de bits que se utilizan para representar cada gen
     */
    void setFitness(const int* _puzzle_size, const int* _total_bits, const int* _bits_per_gene);


    /**
     * @brief Cuenta de izquierda a derecha cuantos valores consecutivos son correctos para determianr el punto a
     *        partir del que conviene más cruzar genes
     * @param father cromosoma padre del cual se realiza el analisis
     * @param _puzzle_size numero de piezas que tiene el puzzle
     * @param _total_bits numero de bits totales que utiliza el cromosoma
     * @param _bits_per_gene numero de bits que se utilizan para representar cada gen
     * @return
     */
    int getCrossoverPoint(Chromosome *father, const int* _puzzle_size, const int *_total_bits, const int *_bits_per_gene);

public:

    /**
     * @brief Constructor utilizado para generar un cromosoma aleatorio para la primera población
     * @param _puzzle_size numero de piezas del puzzle
     * @param total_bits numero total de bits que se necesita cualquier cromosoma para representar un individuo
     * @param _bits_per_gene numero minimo de bits necesarios para formar un gen o celula. En este caso un numero entre
     *                       0 hasta el numero de piezas del puzzle
     */
    Chromosome(const int* _puzzle_size, const int* _total_bits, const int* _bits_per_gene);


    Chromosome(Chromosome* father, Chromosome* mother,const int* _puzzle_size, const int* _total_bits, const int* _bits_per_gene, bool firstChild);

    /**
     * @brief Retorna el fitness del cromosoma ó individuo
     * @return fitness entre mayor sea, más cerca está esta solución de representar al rompecabezas final
     */
    int getFitness() const;

    /**
     * @brief Retorna los valores del cromosoma
     * @return genes
     */
    const boost::dynamic_bitset<> &getGenes() const;

};


#endif //LETSPLAY_CHROMOSOME_H
