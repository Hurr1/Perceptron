#include "../Header/Perceptron.h"
#include "../Header/Algorithm.h"
Perceptron::Perceptron(int pow, int threshold)
        : _power(pow), _threshold(threshold), _firstCase("Iris-setosa"), _secondCase("Iris-virginica")
{
    for (int i = 0; i < _power; i++)
        _weights.emplace_back(0);
}

double Perceptron::at(int index) const
{
    return this->_weights.at(index);
}

double Perceptron::getThreshold() const
{
    return this->_threshold;
}

void Perceptron::teach(Node &a)
{
    double dotProduct = ai::dotProduct( this->_weights, a.getVector() );

    int y = dotProduct < this->_threshold ? 0 : 1;
}

