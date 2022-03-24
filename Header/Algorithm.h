#pragma once

#include <utility>
#include <string>
#include <vector>
#include "Node.h"
#include "TextBox.h"

typedef std::pair<std::string, int> pair;

namespace ai {

    std::vector<Node> createDB(std::istream &str);

    std::vector<Node> createTestDB(std::ifstream &str);

    double dotProduct(std::vector<double>&, std::vector<double>);

    void deltaAlgorithm(std::vector<double>&weights,int correct,int actual,int intensity,std::vector<double>input);

    std::vector<double> multiply(std::vector<double>vector,double factor);

    std::vector<double> sumVectors(std::vector<double>first,std::vector<double>second);

}