//
// Created by fernando on 20/5/21.
//

#include "Backtracking.h"
Tracklist track = Tracklist();
Pathlist path = Pathlist();

Backtracking::Backtracking() {

}

bool Backtracking::Path(int matrix[9][13], int i, int j) {

    if (matrix[i+1][j] == 4 || matrix[i-1][j] == 4 || matrix[i][j+1] == 4 || matrix[i][j-1] == 4 ){
        std::cout << "FOUND" << std::endl;
        path.show();
        founded = true;

    }
    else{
        if (!founded){
            if (counter == 0){
                matrix[i][j] = 1;
            }
            counter++;
//            std::cout << i;
//            std::cout << "-";
//            std::cout << j<<std::endl;

            // Top edge
            if (i == 0 ){
                //TRC
                if (j == 12){

                    if (matrix[i+1][j] == 0 && visited[i+1][j]){
                        matrix[i+1][j] = 1;
                        track.insert(matrix);
                        path.insert(i+1, j);
                        Path(matrix,i+1, j);

                    }
                    else if (matrix[i][j-1] == 0 && visited[i][j-1]){
                        matrix[i][j-1] = 1;
                        track.insert(matrix);
                        path.insert(i, j-1);
                        Path(matrix, i, j-1);
                    }
                    else{
                        visited[i][j] = false;
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        track.remove();
                        Path(matrix, i, j);
                    }

                }
                    //TLC
                else if (j == 0){
                    if (matrix[i][j+1] == 0 && visited[i][j+1]){
                        matrix[i][j+1] = 1;
                        track.insert(matrix);
                        path.insert(i, j+1);
                        Path(matrix, i, j+1);
                    }
                    else if (matrix[i+1][j] == 0 && visited[i+1][j]){
                        matrix[i+1][j] = 1;
                        track.insert(matrix);
                        path.insert(i+1, j);
                        Path(matrix,i+1, j);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }

                }
                else{
                    // Right
                    if (matrix[i][j+1] == 0 && visited[i][j+1]){
                        matrix[i][j+1] = 1;
                        track.insert(matrix);
                        path.insert(i, j+1);
                        Path(matrix, i, j+1);
                    }
                        // Down
                    else if (matrix[i+1][j] == 0 && visited[i+1][j]){
                        matrix[i+1][j] = 1;
                        track.insert(matrix);
                        path.insert(i+1, j);
                        Path(matrix,i+1, j);
                    }
                        // Left
                    else if (matrix[i][j-1] == 0 && visited[i][j-1]){
                        matrix[i][j-1] = 1;
                        track.insert(matrix);
                        path.insert(i, j-1);
                        Path(matrix, i, j-1);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }
                }

            }

                // Bottom edge
            else if (i == 8){
                //BRC
                if (j==12){
                    if (matrix[i-1][j] == 0 && visited[i-1][j]){
                        matrix[i-1][j] = 1;
                        track.insert(matrix);
                        path.insert(i-1, j);
                        Path(matrix, i-1, j);
                    }
                    else if (matrix[i][j-1] == 0 && visited[i][j-1]){
                        matrix[i][j-1] = 1;
                        track.insert(matrix);
                        path.insert(i, j-1);
                        Path(matrix, i, j-1);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }

                }
                    //BLC
                else if (j==0){
                    if (matrix[i][j+1] == 0 && visited[i][j+1]){
                        matrix[i][j+1] = 1;
                        track.insert(matrix);
                        path.insert(i, j+1);
                        Path(matrix, i, j+1);
                    }
                    else if (matrix[i-1][j] == 0 && visited[i-1][j]){
                        matrix[i-1][j] = 1;
                        track.insert(matrix);
                        path.insert(i-1, j);
                        Path(matrix, i-1, j);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }

                }
                else{
                    // Right
                    if (matrix[i][j+1] == 0 && visited[i][j+1]){
                        matrix[i][j+1] = 1;
                        track.insert(matrix);
                        path.insert(i, j+1);
                        Path(matrix, i, j+1);
                    }

                        // UP
                    else if (matrix[i-1][j] == 0 && visited[i-1][j]){
                        matrix[i-1][j] = 1;
                        track.insert(matrix);
                        path.insert(i-1, j);
                        Path(matrix, i-1, j);
                    }

                        // Left
                    else if (matrix[i][j-1] == 0 && visited[i][j-1]){
                        matrix[i][j-1] = 1;
                        track.insert(matrix);
                        path.insert(i, j-1);
                        Path(matrix, i, j-1);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }

                }
            }

                // Right and left edges
            else if (i != 0){
                if (j == 0){
                    if (matrix[i][j+1]==0 && visited[i][j+1]){
                        matrix[i][j+1] = 1;
                        track.insert(matrix);
                        path.insert(i, j+1);
                        Path(matrix, i, j+1);
                    }
                    else if (matrix[i-1][j] == 0 && visited[i-1][j]){
                        matrix[i-1][j] = 1;
                        track.insert(matrix);
                        path.insert(i-1, j);
                        Path(matrix, i-1, j);
                    }
                    else if (matrix[i+1][j] == 0 && visited[i+1][j]){
                        matrix[i+1][j] = 1;
                        track.insert(matrix);
                        path.insert(i+1, j);
                        Path(matrix,i+1, j);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }
                }
                else if(j == 12){
                    //UP
                    if (matrix[i-1][j] == 0 && visited[i-1][j]){
                        matrix[i-1][j] = 1;
                        track.insert(matrix);
                        path.insert(i-1, j);
                        Path(matrix, i-1, j);
                    }
                        //DOWN
                    else if (matrix[i+1][j] == 0 && visited[i+1][j]){
                        matrix[i+1][j] = 1;
                        track.insert(matrix);
                        path.insert(i+1, j);
                        Path(matrix,i+1, j);
                    }
                        //LEFT
                    else if (matrix[i][j-1]==0 && visited[i][j-1]){
                        matrix[i][j-1] = 1;
                        track.insert(matrix);
                        path.insert(i, j-1);
                        Path(matrix, i, j-1);
                    }
                    else{
                        visited[i][j] = false;
                        track.remove();
                        path.remove();
                        memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                        Path(matrix, i, j);
                    }
                }

            }

            // Up
            if (matrix[i-1][j] == 0 && visited[i-1][j]){
                matrix[i-1][j] = 1;
                track.insert(matrix);
                path.insert(i-1, j);
                //track.show();
                Path(matrix, i-1, j);
            }
                // Right
            else if (matrix[i][j+1] == 0 && visited[i][j+1] && j+1 < 13){
                matrix[i][j+1] = 1;
                track.insert(matrix);
                path.insert(i, j+1);
                Path(matrix, i, j+1);
            }
                // Down
            else if (matrix[i+1][j] == 0 && visited[i+1][j]){
                matrix[i+1][j] = 1;
                track.insert(matrix);
                path.insert(i+1, j);
                Path(matrix,i+1, j);
            }
                // Left
            else if (matrix[i][j-1] == 0 && visited[i][j-1]){
                matrix[i][j-1] = 1;
                track.insert(matrix);
                path.insert(i, j-1);
                Path(matrix, i, j-1);
            }
            else{
                visited[i][j] = false;
                track.remove();
                path.remove();
                memcpy(matrix, track.tail->matrix, sizeof(int) * 9 * 13);
                Path(matrix, i, j);
            }

        }

    }

}