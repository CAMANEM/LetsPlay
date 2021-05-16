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


}

void XML::Modification(std::string name, std::string element, std::string info) {
    doc.LoadFile(("../XML Files/"+name+".xml").c_str());
    change = doc.FirstChildElement("ROOT")->FirstChildElement(element.c_str());
    change->SetText(info.c_str());
    doc.SaveFile(("../XML Files/"+name+".xml").c_str());


}

void XML::Elimination(std::string name) {
    remove(("../XML Files/"+name+".xml").c_str());
}
