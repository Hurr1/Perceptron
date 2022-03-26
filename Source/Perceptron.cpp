#include "../Header/Perceptron.h"
#include "../Header/Algorithm.h"
Perceptron::Perceptron(std::size_t pow, double threshold)
        : _power(pow), _threshold(threshold), _cases(std::vector<std::string>{"Iris-setosa","Iris-virginica"})
{
    for (int i = 0; i < _power - 1; i++)
        _weights.emplace_back(1);
}

double Perceptron::getThreshold() const
{
    return this->_threshold;
}

void Perceptron::teach(Node &a,double alpha, int& fails)
{
    double dotProduct = ai::dotProduct( this->_weights, a.getVector() );
    int y = dotProduct >= this->_threshold ? 1 : 0;
    int d;
    if( !_cases.at(y).compare(a.getClass()) ) [[unlikely]]
    {
        y == 0 ? d = 1 : d = 0;
        ai::deltaAlgorithm(this, a.getVector(), d, y, dotProduct, alpha);
        std::cout<<"UnSuccess"<<"["<<a._index<<']'<<" Trying again."<<'\n';
        this->teach(a,alpha, fails);
        fails++;
    }
    else
        std::cout<<"Success"<<"["<<a._index<<']'<<'\n';
}

void Perceptron::findClass(Node &node)
{
    double dotProduct = ai::dotProduct( this->_weights, node.getVector());
    int y = dotProduct < this->_threshold ? 0 : 1;
    node.setClass(this->_cases.at(y));
}

void Perceptron::setThreshold(double value)
{
    this->_threshold = value;
}

std::string Perceptron::getClassAt(std::size_t index)
{
    return this->_cases.at(index);
}

std::vector<double> Perceptron::getVector()
{
    return this->_weights;
}

void Perceptron::setVector(std::vector<double>&& newVector)
{
    if(newVector.size() == this->_power-1)
        this->_weights = std::move(newVector);
}

double Perceptron::at(std::size_t index) const
{
    return this->_weights.at(index);
}

