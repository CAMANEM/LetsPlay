#include <iostream>
#include "GUI/Main_Window.h"
#include "XML/XML.h"
#include "XML/tinyxml2.h"

int main() {

    Main_Window* mainWindow = new Main_Window();
    mainWindow->Run();

//    XML hp = XML();
//    hp.Construction("Fernando");
//    hp.Modification("Fernando", "NAME", "PABLO");
    //hp.Elimination("Fernando");
    return 0;
}