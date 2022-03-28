#include <iostream>
#include <utility>
#include "../Header/Node.h"

int Node::_count = 0;

Node::Node(std::vector<double>&& attrs,std::string lastAttr,std::size_t size)
        : _attrs(std::move(attrs)), _lastAttr(std::move(lastAttr)),_size(size),_index(_count++)
{}

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
    this->_lastAttr = std::move(newClass);
}

sf::Color Node::getColor() const
{
    return this->_color;
}

void Node::setColor(sf::Color color)
{
    this->_color = color;
}

double Node::at(int index) const
{
    return this->_attrs.at(index);
}

std::vector<double> Node::getVector()
{
    return this->_attrs;
}
