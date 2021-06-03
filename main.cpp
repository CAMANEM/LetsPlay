#include <iostream>
#include "GUI/Main_Window.h"
#include "Backtracking/Backtracking.h"

int main() {

//    Main_Window* mainWindow = new Main_Window();
//    mainWindow->Run();
//    int matrix[9][13] = {
//            {0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0},
//            {0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//            {0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1},
//            {0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
//            {0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
//            {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,4},
//            {0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1},
//            {0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//            {0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
//    };
//
//    Backtracking hp = Backtracking();
//    hp.Path(matrix, 7, 2);

    Backtracking hp = Backtracking();
    hp.road(7, 2);
    return 0;
}