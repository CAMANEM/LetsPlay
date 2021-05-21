//
// Created by fernando on 20/5/21.
//

#include "Backtracking.h"
Tracklist prueba = Tracklist();

Backtracking::Backtracking() {

}

bool Backtracking::Path(int matrix[9][13], int i, int j) {

    prueba.insert(matrix);
    prueba.insert(matrix);
    prueba.insert(matrix);
    prueba.insert(matrix);
    prueba.remove();
    prueba.remove();
    prueba.remove();
    prueba.remove();
    prueba.insert(matrix);





//    if (matrix[i][j] == 4){
//        return true;
//    }
//    if (matrix[i][j] == 1){
//        matrix[i][j] = 5;
//        std::cout << j << std::endl;
//        Path(matrix, i, j+1);
//    }

}