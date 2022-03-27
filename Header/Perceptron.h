#pragma once

#include <vector>
#include "Node.h"

class Perceptron
{
public:
    Perceptron(std::size_t pow, double threshold);
    ~Perceptron() = default;

    [[nodiscard]] double getThreshold() const;
    [[nodiscard]] double at(std::size_t index) const;

    void teach(Node& a,double alpha, int& fails);
    void findClass(Node& node);
    void setThreshold(double value);
    void setVector(std::vector<double>&& newVector);
    std::vector<double> getVector();

private:
    std::size_t                      _power;
    double                          _threshold;
    std::vector<std::string>        _cases;
    std::vector<double>             _weights;
};