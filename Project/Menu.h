#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include "TextBox.h"
#include "bouton.h"

#pragma region variables


#pragma endregion variables

void Menu(sf::RenderWindow &window)
{
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Project Programmation", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(true);

    sf::Font arial;
    arial.loadFromFile("arial.ttf");


    /*Textbox textbox1(15, sf::Color::White, false);
    textbox1.setFont(arial);
    textbox1.setPosition({ 100, 100 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        textbox1.setSelected(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        textbox1.setSelected(false);
    } */


    Bouton btn1("Jeu 1", { 200,50 }, 20, sf::Color(202, 202, 202, 190), sf::Color::Black);
    btn1.setPosition({ 100, 300 });
    btn1.setFont(arial);

    while (window.isOpen()) {
        sf::Event Event;
        while (window.pollEvent(Event)) {
            switch (Event.type) {
            case sf::Event::Closed:
                window.close();
            //case sf::Event::TextEntered:
              //  textbox1.typedOn(Event);
            case sf::Event::MouseMoved:
                if (btn1.isMouseOver(window)) {
                    btn1.setBackColor(sf::Color::White);
                }
                else {
                    btn1.setBackColor(sf::Color::Black);
                }
            }
        }
        window.clear();
        btn1.drawTo(window);
        //textbox1.drawTo(window);
        window.display();
    }
}