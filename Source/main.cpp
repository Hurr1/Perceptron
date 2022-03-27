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

            //The variable will be assigned the value 0.1 if(k<=0 or k>1)
            k = (k <=0 || k > 1) ? 0.1 : k;

            dataBase = ai::createDB(trainSet);
            testDataBase = ai::createDB(testSet);

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

            Perceptron prcp(dataBase.at(0).getSize(),1);
            prcp = ai::teachPerceptron(prcp,dataBase, k);
            prcp = ai::teachPerceptron(prcp,dataBase, k);;
            prcp = ai::teachPerceptron(prcp,dataBase, k);


            ai::testCases(prcp,testDataBase);
        }else{
            trainSet ? std::cout<<"There no file with name: "<<argv[3]<<'\n' : std::cout<<"There no file with name: " << argv[2]<<'\n';
            return EXIT_FAILURE;
        }
    }else{
        std::cout<<"Invalid number of arguments"<<'\n';
    }
    return EXIT_SUCCESS;
}
