#include <iostream>
#include <fstream>
#include "rapidxml.hpp"

using namespace rapidxml;

// HTML headers and style
std::string GetHTMLHeaders(){
    return  "<!DOCTYPE html><html><head><style>table { font-family: arial, sans-serif;  border-collapse: collapse;}"
            "td, th {border: 1px solid #dddddd;text-align: left;  padding: 8px;}th{ background-color: #dddddd;}</style></head><body>";
}


// Function to convert XML to HTML
std::string convertXmlToHtml(const std::string& xmlFilename, const std::string& htmlFilename) {
    std::ifstream xmlFile;
    xmlFile.open(xmlFilename);
    if (!xmlFile.is_open()) {
        std::cerr << "Failed to open XML file: " << xmlFilename << std::endl;
        return "";
    }

    // Read the XML file into a string
    std::string xmlContent((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>());
    xmlFile.close();

    // Parse the XML content
    xml_document<> xmlDoc;
    xmlDoc.parse<0>(&xmlContent[0]);

    xml_node<>* root_node = xmlDoc.first_node();


    // Convert each XML node to HTML
    std::string htmlTable = GetHTMLHeaders();

    // First child picked to assign table headers
    rapidxml::xml_node<>* firstChild = root_node->first_node();

    htmlTable += "<table>\n";
    htmlTable += "<tr>\n";
    for (rapidxml::xml_node<>* headernode = firstChild->first_node(); headernode; headernode = headernode->next_sibling()) {

        htmlTable += "<th>" + std::string(headernode->name()) + "</th>";
    }
    htmlTable += "</tr>\n";
    // Iterate over the XML nodes and generate HTML rows
    for (rapidxml::xml_node<>* child = root_node->first_node(); child; child = child->next_sibling()) {
        htmlTable += "<tr>\n";

        // Iterate over XML attributes and generate HTML cells
        for (rapidxml::xml_node<>* childnode = child->first_node(); childnode; childnode = childnode->next_sibling()) {
            htmlTable += "<td>" + std::string(childnode->value()) + "</td>";
        }

        htmlTable += "</tr>\n";
    }

    htmlTable += "</body></table>\n";

    std::cout << "XML to HTML conversion completed successfully!" << std::endl;

    return  htmlTable;
}

int main() {
    std :: cout<< "Enter the XML file name : ";
    std::string xmlFilename;
    std :: getline(std::cin, xmlFilename);
    std::cout << "Processing " << xmlFilename << std::endl;


    std::string htmlFilename = "output.html";
    std::string htmltable =  convertXmlToHtml(xmlFilename, htmlFilename);

    std::ofstream output(htmlFilename);
    output << htmltable;
    output.close();
    std :: cin.get();
    return 0;
}