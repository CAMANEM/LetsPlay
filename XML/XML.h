//
// Created by fernando on 14/5/21.
//

#ifndef LETSPLAY_XML_H
#define LETSPLAY_XML_H

#include "tinyxml2.h"
#include <iostream>
#include <string>

using namespace tinyxml2;

class XML {

public:
    XML();
    void Construction(std::string name);


private:
    XMLDocument doc;

};


#endif //LETSPLAY_XML_H
