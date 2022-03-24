#include <iostream>
#include <utility>
#include "../Header/Node.h"

Node::Node(std::vector<double> attrs,std::string lastAttr,int size)
        : _attrs(std::move(attrs)), _lastAttr(std::move(lastAttr)),_size(size)
{}

double Node::at(int index) const
{
    return this->_attrs[index];
}


void Node::printNode() const
{
    for(double i : _attrs)
        std::cout<<"["<<i<<']';
    std::cout<<"["<<_lastAttr<<']'<<'\n';
}

std::size_t Node::getSize() const
{
    return this->_size;
}

std::string Node::getClass() const
{
    return this->_lastAttr;
}

void Node::setClass(std::string newClass)
{
    this->_lastAttr = newClass;
}
/*
sf::Color Node::getColor() const
{
    return _color;
}

void Node::setColor(sf::Color color)
{
    this->_color = color;
}
 */

std::vector<double> Node::getVector()
{
    return this->_attrs;
}
