#pragma once

#include <utility>
#include <string>
#include <vector>
#include "Node.h"
#include "TextBox.h"
#include "Perceptron.h"

typedef std::pair<std::string, int> pair;

namespace ai {

    std::vector<Node> createDB(std::istream &str);

    std::vector<Node> createTestDB(std::ifstream &str);

    double dotProduct(std::vector<double> weights, std::vector<double>inputs);

    void deltaAlgorithm(Perceptron* prc, std::vector<double>input,int d, int y,double threshold,double dotProduct,double alpha);

    std::vector<double> multiply(std::vector<double> vector,double factor);

    std::vector<double> sumVectors(std::vector<double>first,std::vector<double>second);

    Perceptron teachPerceptron(Perceptron p, std::vector<Node>&trainingSet, double delta);

}