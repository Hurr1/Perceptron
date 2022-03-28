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

    std::vector<double> multiply(std::vector<double> &&vector, double factor);

    std::vector<double> sumVectors(std::vector<double>&& first, std::vector<double>&& second);

    Perceptron teachPerceptron(Perceptron perceptron, std::vector<Node> &trainingSet, double delta);

    void testCases(Perceptron &perceptron, std::vector<Node> &dataBase);

    void setNodesColor(std::vector<Node> &dataBase);

    void setNodeColor(Node & node);

    std::vector<std::pair<std::string,std::pair<int,int>>> getAxes();

    void drawPoints(sf::RenderWindow& rn,sf::Text header, std::vector<Node>& data, sf::CircleShape& point, int& level, std::vector<std::pair<std::string,std::pair<int,int>>> axes,short lastPage, Perceptron perceptron);

    int comb(std::size_t N, int K);

    int factorial(int n);

    Node tokenize(const std::string& s, Textbox &input, std::size_t size, const std::string& del);
}