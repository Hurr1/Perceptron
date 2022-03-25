#pragma once

#include <vector>
#include "Node.h"

class Perceptron
{
public:
    Perceptron(int pow, int threshold);
    ~Perceptron() = default;

    double at(int index) const;
    double getThreshold() const;
    void teach(Node& a);


private:
    std::vector<double>     _weights;
    double                  _power;
    double                  _threshold;
    std::string             _firstCase;
    std::string             _secondCase;
};