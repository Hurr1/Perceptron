#include "../Header/Algorithm.h"
#include "../Header/CSVRow.h"
#include "../Header/Perceptron.h"

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

std::vector<Node> ai::createDB(std::istream& str)
{
    CSVRow row;
    std::vector<Node> data;
    std::vector<double>toAdd;
    while(str >> row)
    {
        for(int i = 0; i< row.size()-1;i++)
            toAdd.emplace_back(std::stod(row[i]));
        data.emplace_back(Node(toAdd,row[row.size()-1],row.size()));
        toAdd.clear();
    }
    return data;
}

std::vector<Node> ai::createTestDB(std::ifstream& str)
{
    CSVRow row;
    std::vector<Node> data;
    std::vector<double>toAdd;

    while(str >> row)
    {
        for(int i = 0; i< row.size()-1;i++)
            toAdd.emplace_back(std::stod(row[i]));
        data.emplace_back(Node(toAdd,"UNDEFIEND",row.size()));
        toAdd.clear();
    }
    return data;
}

double ai::dotProduct(std::vector<double> weights, std::vector<double>inputs)
{
    double dotProduct = 0;
    for(int i =0;i<weights.size();i++)
    {
        dotProduct = dotProduct + (weights.at(i) * inputs.at(i));
    }
    return dotProduct;
}

Perceptron ai::teachPerceptron(Perceptron p, std::vector<Node>&trainingSet, double delta)
{
    for(Node &a : trainingSet)
        p.teach(a,delta);

    return p;
}

void ai::deltaAlgorithm(Perceptron* prc, std::vector<double>input,int d, int y,double threshold,double dotProduct,double alpha)
{
    std::vector<double>res;

    input.push_back(dotProduct);
    prc->_weights.push_back(prc->_threshold);

    input = ai::multiply(input,(d-y)*alpha);

    res = ai::sumVectors(prc->_weights, input);

    prc->_threshold = res.at(res.size()-1);
    res.pop_back();
    prc->_weights = res;
}

std::vector<double> ai::multiply(std::vector<double> vector,double factor)
{
    std::for_each(vector.begin(),vector.end(),[factor](double &value){value *= factor;});
    return vector;
}

std::vector<double> ai::sumVectors(std::vector<double>first,std::vector<double>second)
{
    std::transform (first.begin(), first.end(), second.begin(), first.begin(), std::plus<double>());
    return first;
}
