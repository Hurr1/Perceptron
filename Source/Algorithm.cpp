#include <iomanip>
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
        data.emplace_back(Node(std::forward<std::vector<double>>(toAdd),row[row.size()-1],row.size()));
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
        data.emplace_back(Node(std::forward<std::vector<double>>(toAdd),"UNDEFIEND",row.size()));
        toAdd.clear();
    }
    return data;
}

double ai::dotProduct(std::vector<double> weights, std::vector<double>inputs)
{
    double dotProduct = 0;
    for(int i =0;i<weights.size();i++)
        dotProduct = dotProduct + (weights.at(i) * inputs.at(i));
    return dotProduct;
}

Perceptron ai::teachPerceptron(Perceptron perceptron, std::vector<Node>&trainingSet, double delta)
{
    int fails = 0;
    for(Node &a : trainingSet)
        perceptron.teach(a, delta, fails);
    std::string weightsString = "|";
    std::string s;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2);
    for(int i =0; i < perceptron.getVector().size(); i++)
    {
        stream << perceptron.at(i);
        s = stream.str();
        weightsString = weightsString + s + "|";
        stream.str("");
    }

    std::cout << "-----------FEEDBACK-----------" << '\n'
              << "Successful attempts   : " << trainingSet.size()-fails << '\n'
              << "Unsuccessful attempts : " << fails << '\n'
              << "------------------------------" << '\n'
              << "Amount of attempts    : " << trainingSet.size() << '\n'
              << "------------------------------" << '\n'
              << "Vector    : " << weightsString << '\n'
              << "Therehold : |" << perceptron.getThreshold() << '|' << '\n'
             <<"------------------------------"<<'\n';
    return perceptron;
}

void ai::deltaAlgorithm(Perceptron* prc, std::vector<double>input,int d, int y, double dotProduct,double alpha)
{
    std::vector<double> res = {};
    std::vector<double> weights = prc->getVector();

    input.push_back(dotProduct);
    weights.push_back(prc->getThreshold());

    input = ai::multiply(input,(d-y)*alpha);

    res = ai::sumVectors(weights, input);

    prc->setThreshold(res.at(res.size()-1));
    res.pop_back();

    prc->setVector(std::move(res));
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

void ai::testCases(Perceptron& perceptron, std::vector<Node>& dataBase)
{
    std::size_t index = 0;
    for(Node& testOne : dataBase)
    {
        perceptron.findClass(testOne);
        std::cout<< "[" << index++ << ']' << "["<<testOne.getClass()<<']'<<'\n';
    }
}
