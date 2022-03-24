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
    std::vector<double> weights;
    double power;
    double threshold;
};