#pragma once

#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"

class Node
{
public:
    Node(std::vector<double>&& attributes,std::string lastAttr,std::size_t size);
    ~Node() = default;

    void setClass(std::string newClass);
/*
    void setColor(sf::Color color);
    sf::Color getColor() const;
*/


    std::size_t getSize() const;
    std::string getClass() const;
    std::vector<double> getVector();

public:
    static int              _count;
    int                     _index;

private:
    std::vector<double>     _attrs;
    std::string             _lastAttr;
    std::size_t             _size;

    //sf::Color               _color;

};