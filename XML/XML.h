//
// Created by fernando on 14/5/21.
//

#ifndef LETSPLAY_XML_H
#define LETSPLAY_XML_H

#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace tinyxml2;

class XML {

public:

    /**
     * @brief Creates and saves the basic structure of an XML file
     * @param name of the file that is going to be saved
     */
    void Construction(std::string name);

    /**
     * @brief modifies an specific element of an XML file
     * @param name of the file that is gonna be modified
     * @param element that is gonna be modified
     * @param info that is gonna be placed in to the modified element
     */
    void Modification(std::string name, std::string element, std::string info);

    /**
     * @brief deletes an specific XML file
     * @param name of the file that is gonna be deleted
     */
    void Elimination(std::string name);


    /**
     * @brief returns the string inside the the XML file
     * @param file name
     * @return vector inside the file
     */
    std::string Population(int file);

    /**
     * @brief Constructor
     */
    XML();


private:
    XMLDocument doc;
    XMLElement* change;
    int counter = 0;
};


#endif //LETSPLAY_XML_H
