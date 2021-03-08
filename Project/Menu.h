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
sf::CircleShape Base3(450,1000000);
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


    Bouton jouer("Jouer !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1,4,4);
    jouer.setPosition({ 450 - 50, 500 - 25 });
    jouer.setFont(arial);

    Bouton placer("Placer !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 5, 4);
    placer.setPosition({ 183 - 50, 500 - 25 });
    placer.setFont(arial);

    Bouton solution("Solution !", { 125,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 5, 4);
    solution.setPosition({ 183 - 62.5, 600 - 25 });
    solution.setFont(arial);

    Bouton sauvegarder("Sauvegarder !", { 125,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 9, 4);
    sauvegarder.setPosition({ 717 - 62.5, 600 - 25 });
    sauvegarder.setFont(arial);

    Bouton charger("Charger !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 6, 4);
    charger.setPosition({ 717 - 50, 500 - 25 });
    charger.setFont(arial);

    Bouton quitter("Quitter !", { 100,50 }, 16, sf::Color(202, 202, 202, 190), sf::Color::White, sf::Color::Black, 1, 5, 4);
    quitter.setPosition({ 450 - 50, 700 - 25 });
    quitter.setFont(arial);

    while (window.isOpen()) {
        sf::Event Event;
        while (window.pollEvent(Event)) {
            switch (Event.type) {
            case sf::Event::Closed:
                window.close();
            //case sf::Event::TextEntered:
              //  textbox1.typedOn(Event);
            case sf::Event::MouseMoved:
                if (jouer.isMouseOver(window)) {
                    jouer.setBackColor(sf::Color(54, 58, 59));
                    jouer.setTextColor(sf::Color(66, 156, 227));
                }
                else if (placer.isMouseOver(window)) {
                    placer.setBackColor(sf::Color(54, 58, 59));
                    placer.setTextColor(sf::Color(66, 156, 227));
                }
                else if (solution.isMouseOver(window)) {
                    solution.setBackColor(sf::Color(54, 58, 59));
                    solution.setTextColor(sf::Color(66, 156, 227));
                }
                else if (sauvegarder.isMouseOver(window)) {
                    sauvegarder.setBackColor(sf::Color(54, 58, 59));
                    sauvegarder.setTextColor(sf::Color(66, 156, 227));
                }
                else if (charger.isMouseOver(window)) {
                    charger.setBackColor(sf::Color(54, 58, 59));
                    charger.setTextColor(sf::Color(66, 156, 227));
                }
                else if (quitter.isMouseOver(window)) {
                    quitter.setBackColor(sf::Color(54, 58, 59));
                    quitter.setTextColor(sf::Color(66, 156, 227));
                }
                else {
                    jouer.setBackColor(sf::Color(32, 36, 37));
                    jouer.setTextColor(sf::Color::White);

                    placer.setBackColor(sf::Color(32, 36, 37));
                    placer.setTextColor(sf::Color::White);

                    solution.setBackColor(sf::Color(32, 36, 37));
                    solution.setTextColor(sf::Color::White);

                    sauvegarder.setBackColor(sf::Color(32, 36, 37));
                    sauvegarder.setTextColor(sf::Color::White);

                    charger.setBackColor(sf::Color(32, 36, 37));
                    charger.setTextColor(sf::Color::White);

                    quitter.setBackColor(sf::Color(32, 36, 37));
                    quitter.setTextColor(sf::Color::White);
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
            if (quitter.isMouseOver(window)) {
                std::cout << "Quitter" << std::endl;
                window.close();
            }
            if (jouer.isMouseOver(window)) {

            }
        }

        jouer.drawTo(window);
        placer.drawTo(window);
        solution.drawTo(window);
        sauvegarder.drawTo(window);
        charger.drawTo(window);
        quitter.drawTo(window);

        //textbox1.drawTo(window);
        window.display();
    }
}