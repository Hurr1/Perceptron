#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {

public:
    sf::Text                        textbox;
private:
    std::ostringstream              text;
    bool                            isSelected = false;
    bool                            hasLimit = false;
    int                             limit = 0;


public:

    Textbox(int size,sf::Color color, bool sel);
    void setFont(sf::Font &fonts);
    void setPosition(sf::Vector2f point);
    void setLimit(bool ToF);
    void setLimit(bool ToF, int lim);
    void setSelected(bool sel);

    std::string getText();
    void drawTo(sf::RenderWindow &window) const;
    void typedOn(sf::Event input);

private:

    void deleteLastChar();
    void inputLogic(int charTyped);

};