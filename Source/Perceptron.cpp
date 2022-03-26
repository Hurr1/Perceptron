#include "../Header/Perceptron.h"
#include "../Header/Algorithm.h"
Perceptron::Perceptron(int pow, double threshold)
        : _power(pow), _threshold(threshold), cases(std::vector<std::string>{"Iris-setosa","Iris-virginica"})
{
    for (int i = 0; i < _power; i++)
        _weights.emplace_back(1);
}

double Perceptron::at(int index) const
{
    return this->_weights.at(index);
}

double Perceptron::getThreshold() const
{
    return this->_threshold;
}

void Perceptron::teach(Node &a,double alpha)
{
    double dotProduct = ai::dotProduct( this->_weights, a._attrs );
    int y = dotProduct < this->_threshold ? 0 : 1;
    int d;
    if( !cases.at(y).compare(a.getClass()) )
    {
        y == 0 ? d = 1 : d = 0;
        ai::deltaAlgorithm(this, a.getVector(),d,y, this->getThreshold(),dotProduct,alpha);
        std::cout<<"UnSuccess"<<"["<<a._index<<']'<<'\n';
        this->teach(a,alpha);
    }
    else
        std::cout<<"Success"<<"["<<a._index<<']'<<'\n';
}

void Perceptron::findClass(Node &node)
{
    double dotProduct = ai::dotProduct( this->_weights, node._attrs);
    int y = dotProduct < this->_threshold ? 0 : 1;
    node.setClass(this->cases.at(y));
}

