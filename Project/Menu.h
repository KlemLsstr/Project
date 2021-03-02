#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include "TextBox.h"
#include "bouton.h"



#pragma region variables
sf::RectangleShape Base;
sf::RectangleShape Base2;
sf::CircleShape Base3;
sf::CircleShape Base4(70,3);
sf::RectangleShape Base5;
sf::RectangleShape Base6;
sf::Text Titre;

#pragma endregion variables

void Menu(sf::RenderWindow &window)
{
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Project Programmation", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(true);

#pragma region initialisation
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    sf::Font Brannboll;
    Brannboll.loadFromFile("Brannboll.ttf");

    /*Creation du Menu */
    Base.setSize({ 850,850 });
    Base.setPosition({ 25,25 });
    Base.setFillColor(sf::Color(220,220,220));

    Base2.setSize({ 900,900 });
    Base2.setPosition({ 0,0 });
    Base2.setFillColor(sf::Color::Black);

    Base3.setRadius(450);
    Base3.setPosition({ 0,0 });
    Base3.setFillColor(sf::Color(220,220,220));

    Titre.setString("| Bataille Navale |");
    Titre.setFont(Brannboll);
    Titre.setCharacterSize(96);
    Titre.setPosition({ 900 / 8,100 });
    Titre.setFillColor(sf::Color(48, 150, 205));

    Base4.setOutlineColor(sf::Color(48, 150, 205));
    Base4.setFillColor(sf::Color(220, 220, 220));
    Base4.setOutlineThickness(2);
    Base4.setPosition({ 380,5 });

    Base5.setSize({ 650, 20 });
    Base5.setOutlineColor(sf::Color(48, 150, 205));
    Base5.setOutlineThickness(2);
    Base5.setFillColor(sf::Color(220, 220, 220));
    Base5.setPosition({ 125,215 });

    Base6.setSize({ 800, 550 });
    Base6.setOutlineColor(sf::Color(54, 58, 59));
    Base6.setOutlineThickness(10);
    Base6.setPosition({ 50,300 });

#pragma endregion initialisation

    /*Textbox textbox1(15, sf::Color::White, false);
    textbox1.setFont(arial);
    textbox1.setPosition({ 100, 100 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        textbox1.setSelected(true);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        textbox1.setSelected(false);
    } */


    Bouton btn1("Jouer !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1,4,4);
    btn1.setPosition({ 450 - 50, 500 - 25 });
    btn1.setFont(arial);

    Bouton btn2("Placer !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 5, 4);
    btn2.setPosition({ 183 - 50, 500 - 25 });
    btn2.setFont(arial);

    Bouton btn3("Solution !", { 125,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 5, 4);
    btn3.setPosition({ 183 - 62.5, 600 - 25 });
    btn3.setFont(arial);

    Bouton btn4("Sauvegarder !", { 125,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 9, 4);
    btn4.setPosition({ 717 - 62.5, 600 - 25 });
    btn4.setFont(arial);

    Bouton btn5("Charger !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 6, 4);
    btn5.setPosition({ 717 - 50, 500 - 25 });
    btn5.setFont(arial);

    Bouton btn6("Quitter !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 5, 4);
    btn6.setPosition({ 450 - 50, 700 - 25 });
    btn6.setFont(arial);

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
                    btn1.setBackColor(sf::Color(54, 58, 59));
                    btn1.setTextColor(sf::Color(66, 156, 227));
                }
                else if (btn2.isMouseOver(window)) {
                    btn2.setBackColor(sf::Color(54, 58, 59));
                    btn2.setTextColor(sf::Color(66, 156, 227));
                }
                else if (btn3.isMouseOver(window)) {
                    btn3.setBackColor(sf::Color(54, 58, 59));
                    btn3.setTextColor(sf::Color(66, 156, 227));
                }
                else if (btn4.isMouseOver(window)) {
                    btn4.setBackColor(sf::Color(54, 58, 59));
                    btn4.setTextColor(sf::Color(66, 156, 227));
                }
                else if (btn5.isMouseOver(window)) {
                    btn5.setBackColor(sf::Color(54, 58, 59));
                    btn5.setTextColor(sf::Color(66, 156, 227));
                }
                else if (btn6.isMouseOver(window)) {
                    btn6.setBackColor(sf::Color(54, 58, 59));
                    btn6.setTextColor(sf::Color(66, 156, 227));
                }
                else {
                    btn1.setBackColor(sf::Color(32, 36, 37));
                    btn1.setTextColor(sf::Color::White);

                    btn2.setBackColor(sf::Color(32, 36, 37));
                    btn2.setTextColor(sf::Color::White);

                    btn3.setBackColor(sf::Color(32, 36, 37));
                    btn3.setTextColor(sf::Color::White);

                    btn4.setBackColor(sf::Color(32, 36, 37));
                    btn4.setTextColor(sf::Color::White);

                    btn5.setBackColor(sf::Color(32, 36, 37));
                    btn5.setTextColor(sf::Color::White);

                    btn6.setBackColor(sf::Color(32, 36, 37));
                    btn6.setTextColor(sf::Color::White);
                }
            }
        }
#pragma region initialisation2
        window.clear();
        window.draw(Base2);
        window.draw(Base);
        window.draw(Base3);
        window.draw(Titre);
        window.draw(Base4);
        window.draw(Base5);
        window.draw(Base6);
#pragma endregion initialisation2


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (btn6.isMouseOver(window)) {
                std::cout << "Quitter" << std::endl;
                window.close();
            }
        }

        btn1.drawTo(window);
        btn2.drawTo(window);
        btn3.drawTo(window);
        btn4.drawTo(window);
        btn5.drawTo(window);
        btn6.drawTo(window);

        //textbox1.drawTo(window);
        window.display();
    }
}