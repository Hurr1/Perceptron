#pragma once

#include <vector>
#include "Node.h"

class Perceptron
{
public:
    Perceptron(int pow, double threshold);
    ~Perceptron() = default;

    double at(int index) const;
    double getThreshold() const;
    void teach(Node& a,double alpha);
    void findClass(Node& node);


public:
    std::vector<double>             _weights;
    double                          _power;
    double                          _threshold;
    std::vector<std::string>        cases;

};