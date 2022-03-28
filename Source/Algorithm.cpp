#include <iomanip>
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
        data.emplace_back(Node(std::forward<std::vector<double>>(toAdd),row[row.size()-1],row.size()));
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
        weightsString += s + "|";
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
    weights.push_back(-1);

    input = ai::multiply(std::move(input),(d-y)*alpha);

    res = ai::sumVectors(std::move(weights), std::move(input));

    prc->setThreshold(res.at(res.size()-1));
    res.pop_back();

    prc->setVector(std::move(res));
}

std::vector<double> ai::multiply(std::vector<double> &&vector,double factor)
{
    std::for_each(vector.begin(),vector.end(),[factor](double &value){value *= factor;});
    return vector;
}

void ai::setNodesColor(std::vector<Node> &dataBase)
{
    for (Node &node: dataBase)
    {
        node.getClass().compare("Iris-setosa") == 0 ? node.setColor(sf::Color::Red) : node.setColor(sf::Color::Green);
    }
}

void ai::setNodeColor(Node & node)
{
    node.getClass().compare("Iris-setosa") == 0 ? node.setColor(sf::Color::Red) : node.setColor(sf::Color::Green);
}

void ai::drawPoints(sf::RenderWindow& rn,sf::Text header, std::vector<Node>& data, sf::CircleShape& point, int& level, std::vector<std::pair<std::string,std::pair<int,int>>> axes,short lastPage)
{
    if(level >= lastPage)
        level = 0;
    else if(level < 0)
        level = ai::comb(data.at(0).getSize()-1,2) -1;
    if(ai::comb(data.at(0).getSize()-1,2) -1 == -1)
        level = 0;
    for (Node &node: data)
    {
        point.setPosition
        (
                {
                    static_cast<float>((node.at(axes.at(level).second.first))*100),
                    static_cast<float>((node.at(axes.at(level).second.second))*100)
                }
        );
        point.setFillColor(node.getColor());
        rn.draw(point);

    }

    header.setString(axes.at(level).first);
    rn.draw(header);

}

std::vector<double> ai::sumVectors(std::vector<double>&& first,std::vector<double>&& second)
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

Node ai::tokenize(const std::string& s,Textbox& input, std::size_t size, const std::string& del = " ")
{
    size_t start;
    size_t end = 0;
    std::vector<double> toAdd;

    try {
        while ((start = s.find_first_not_of(del, end)) != std::string::npos)
        {
            end = s.find(del, start);
            toAdd.push_back(std::stod(s.substr(start, end - start)));

        }
        std::size_t vecSize = toAdd.size();
        Node node (std::move(toAdd), "UNDERFINED", size);

        if(node.getVector().size()<size-1)
        {
            input.textbox.setString("Vector is too small");
            return {{},"ERROR",0};
        }
        else if(node.getVector().size()>size-1)
        {
            input.textbox.setString("Vector is too big");
            return {{},"ERROR",0};
        }

        return node;
    }
    catch (std::exception& e)
    {
        input.textbox.setString("Not a vector");
        return {{},"ERROR",0};
    }
}

std::vector<std::pair<std::string,std::pair<int,int>>> ai::getAxes()
{
    std::vector<std::pair<std::string,std::pair<int,int>>>axes;
    axes.emplace_back("X & Y",std::make_pair(0,1));

    axes.emplace_back("X & Z",std::make_pair(0,2));
    axes.emplace_back("Y & Z",std::make_pair(1,2));

    axes.emplace_back("X & W",std::make_pair(0,3));
    axes.emplace_back("Y & W",std::make_pair(1,3));
    axes.emplace_back("Z & W",std::make_pair(2,3));

    axes.emplace_back("X & V",std::make_pair(0,4));
    axes.emplace_back("Y & V",std::make_pair(1,4));
    axes.emplace_back("Z & V",std::make_pair(2,4));
    axes.emplace_back("W & V",std::make_pair(3,4));

    axes.emplace_back("X & U",std::make_pair(0,5));
    axes.emplace_back("Y & U",std::make_pair(1,5));
    axes.emplace_back("Z & U",std::make_pair(2,5));
    axes.emplace_back("W & U",std::make_pair(3,5));
    axes.emplace_back("V & U",std::make_pair(4,5));

    axes.emplace_back("X & R",std::make_pair(0,6));
    axes.emplace_back("Y & R",std::make_pair(1,6));
    axes.emplace_back("Z & R",std::make_pair(2,6));
    axes.emplace_back("W & R",std::make_pair(3,6));
    axes.emplace_back("V & R",std::make_pair(4,6));
    axes.emplace_back("U & R",std::make_pair(5,6));

    axes.emplace_back("X & S",std::make_pair(0,7));
    axes.emplace_back("Y & S",std::make_pair(1,7));
    axes.emplace_back("Z & S",std::make_pair(2,7));
    axes.emplace_back("W & S",std::make_pair(3,7));
    axes.emplace_back("V & S",std::make_pair(4,7));
    axes.emplace_back("U & S",std::make_pair(5,7));
    axes.emplace_back("R & S",std::make_pair(6,7));

    axes.emplace_back("X & T",std::make_pair(0,8));
    axes.emplace_back("Y & T",std::make_pair(1,8));
    axes.emplace_back("Z & T",std::make_pair(2,8));
    axes.emplace_back("W & T",std::make_pair(3,8));
    axes.emplace_back("V & T",std::make_pair(4,8));
    axes.emplace_back("U & T",std::make_pair(5,8));
    axes.emplace_back("R & T",std::make_pair(6,8));
    axes.emplace_back("S & T",std::make_pair(7,8));

    return axes;
}

int ai::factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int ai::comb(std::size_t N, int K)
{
    return ai::factorial(static_cast<int>(N)) / (ai::factorial(K) * ai::factorial(static_cast<int>(N) - K));
}