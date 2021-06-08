#include <iostream>
#include "GUI/Main_Window.h"
#include "XML/XML.h"
#include "XML/tinyxml2.h"
#include <vector>


#include <iostream>
#include <string>
#include <vector>

int main() {

//    std::vector<int> input({1,2,3,4,5,6}) ;
//    std::string s(input.begin(), input.end());
//
//    std::vector<int> aux(s.begin(), s.end());
//    std::cout << aux[4];



//    Main_Window* mainWindow = new Main_Window();
//    mainWindow->Run();


std::string Trump = "{";
std::vector<int> charly = {};



    XML hp = XML();

    for (int i = 0; i < 10; ++i) {
        Trump += std::to_string(i);
        Trump += ",";
    }
    Trump += std::to_string(11);

    Trump += "}";


    hp.Construction(Trump);
    hp.Population(0);


    return 0;
}