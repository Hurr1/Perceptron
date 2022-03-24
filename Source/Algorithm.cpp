#include "../Header/Algorithm.h"
#include "../Header/CSVRow.h"

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

double ai::dotProduct(std::vector<double>&weights, std::vector<double>inputs)
{
    double dotProduct = 0;
    for(int i =0;i<weights.size();i++)
    {
        dotProduct = dotProduct + (weights.at(i) * inputs.at(i));
    }
    return dotProduct;
}

void ai::deltaAlgorithm(std::vector<double>&weights,int correct,int actual,int intensity,std::vector<double>input)
{
    weights = ai::sumVectors(weights, ai::multiply( input,((correct - actual)*intensity)));
}

std::vector<double> ai::multiply(std::vector<double>vector,double factor)
{
    std::for_each(vector.begin(),vector.end(),[factor](double &member){member *= factor;});
    return vector;
}

std::vector<double> ai::sumVectors(std::vector<double>first,std::vector<double>second)
{
    std::transform (first.begin(), first.end(), second.begin(), first.begin(), std::plus<double>());
    return first;
}