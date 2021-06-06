//
// Created by fernando on 14/5/21.
//

#include "XML.h"

XML::XML() {

}

void XML::Construction(std::vector<int> name) {

    std::string file =
            "<?xml version=\"1.0\"?>"
            "<ROOT> "
            "<POPULATION>" + (std::string(name.begin(), name.end()))+"</POPULATION>"
             "</ROOT>";


    static const char* xml = file.c_str();
    doc.Parse(xml);
    doc.SaveFile(("../XMLFiles/"+ std::to_string(counter)+ ".xml").c_str());
    counter++;

}

void XML::Modification(std::string name, std::string element, std::string info) {
    doc.LoadFile(("../XMLFiles/"+name+".xml").c_str());
    change = doc.FirstChildElement("ROOT")->FirstChildElement(element.c_str());
    change->SetText(info.c_str());
    doc.SaveFile(("../XMLFiles/"+name+".xml").c_str());

}

void XML::Elimination(std::string name) {
    remove(("../XMLFiles/"+name+".xml").c_str());
}

std::vector<int> XML::Population(int file) {
    doc.LoadFile(("../XMLFiles/"+std::to_string(file)+".xml").c_str());
    change = doc.FirstChildElement("ROOT")->FirstChildElement("POPULATION");
    std::string aux = change->GetText();
    std::vector<int> vector_aux(aux.begin(), aux.end());

    return vector_aux;
}
