#include "../Header/CSVRow.h"
#include <iostream>
#include "../Header/Node.h"
#include <cmath>
#include "../Header/Algorithm.h"
#include "../Header/Button.h"
#include "../Header/Perceptron.h"
#include <SFML/Graphics.hpp>
#define ARGS_NUMBER argc-1
int main(int argc, char* argv[]) {

    if (ARGS_NUMBER == 3) {
        std::ifstream trainSet("Resources/" + static_cast<std::string>(argv[2])),
                      testSet("Resources/" + static_cast<std::string>(argv[3]));
        std::vector<Node> dataBase;
        std::vector<Node> testDataBase;

        if (trainSet && testSet)
        {
            double k = std::stod(argv[1]);

            dataBase = ai::createDB(trainSet);
            testDataBase = ai::createTestDB(testSet);

            {
                if (dataBase.empty() || testDataBase.empty())
                {
                    if (dataBase.empty())
                        std::cout << "TrainingSet.cvs is empty." << '\n';
                    if (testDataBase.empty())
                        std::cout << "TestSet.cvs is empty." << '\n';

                    std::cout << "Programs ends with exit code 0" << '\n';
                    exit(1);
                }
                if (dataBase.at(0).getSize() == 0 || dataBase.at(0).getSize() == 0)
                {
                    std::cout << "Vector is empty." << '\n' << "Programs ends with exit code 0" << '\n';
                    exit(1);
                }
            }

            Perceptron prcp(dataBase.at(0).getSize()-1,k);
            prcp = ai::teachPerceptron(prcp,dataBase, k);
            prcp = ai::teachPerceptron(prcp,dataBase, k);;
            prcp = ai::teachPerceptron(prcp,dataBase, k);

            for(double value : prcp._weights)
            {
                std::cout<<value<<", ";
            }
            std::cout<<'\n'<<prcp._threshold<<'\n';


            for(Node& testOne : testDataBase)
            {
                prcp.findClass(testOne);
                std::cout<< "["<<testOne.getClass()<<']'<<'\n';
            }


        }
    }
}