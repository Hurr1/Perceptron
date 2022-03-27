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

    double dotProduct(std::vector<double> weights, std::vector<double> inputs);

    void deltaAlgorithm(Perceptron *prc, std::vector<double> input, int d, int y, double dotProduct, double alpha);

    std::vector<double> multiply(std::vector<double> vector, double factor);

    std::vector<double> sumVectors(std::vector<double> first, std::vector<double> second);

    Perceptron teachPerceptron(Perceptron perceptron, std::vector<Node> &trainingSet, double delta);

    void testCases(Perceptron &perceptron, std::vector<Node> &dataBase);

    int comb(int N, int K);

    int factorial(int n);

    std::vector<std::pair<std::string, std::pair<int, int>>> getAxes();

    std::vector<Node> tokenize(std::string s, Textbox &input, std::size_t size, std::string del);

}