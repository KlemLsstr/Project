#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>



void Jouer(sf::RenderWindow& window) {
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

    window.create(sf::VideoMode(900, 900), "Project Programmation", sf::Style::Titlebar | sf::Style::Close);
    window.setKeyRepeatEnabled(true);
}