#include "../Header/Perceptron.h"
#include "../Header/Algorithm.h"
Perceptron::Perceptron(int pow, int threshold)
{

    this->power = pow;
    this->threshold = threshold;

    for (int i = 0; i < power; i++)
        weights.emplace_back(0);
}

double Perceptron::at(int index) const
{
    return this->weights.at(index);
}

double Perceptron::getThreshold() const
{
    return this->threshold;
}

void Perceptron::teach(Node &a)
{
    double dotProduct = ai::dotProduct(this->weights, a.getVector());
    if(dotProduct < this->threshold)
    {

    }
}

