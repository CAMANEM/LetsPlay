//
// Created by fernando on 14/5/21.
//

#include "XML.h"

XML::XML() {

}

void XML::Construction(std::string name) {

    std::string hp =
            "<?xml version=\"1.0\"?>"
            "<ROOT> "
            "<NAME>" + name+"</NAME>"
            "</ROOT>";

    static const char* xml = hp.c_str();
    doc.Parse(xml);
    doc.SaveFile(("../XML Files/"+name+".xml").c_str());


//    static const char* xml =
//            "<?xml version=\"1.0\"?>"
//            "<ROOT> "
//            "<NAME>" + a +"</NAME>"
//            "<NAME>FERNANDO MONGE</NAME>"
//            "</ROOT>";

}
