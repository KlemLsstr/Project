#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#pragma region variables
sf::RenderWindow window;
sf::CircleShape cercle(100, 100000);
sf::RectangleShape Base;
int FX = 1920, FY = 1080;   //taille fenêtre en X et Y;
#pragma endregion varaibles


int main(){
    window.create(sf::VideoMode(FX, FY), "Project Programmation");
    window.setFramerateLimit(144);

    std::cout << "Lancement du jeu" << std::endl;

    cercle.setFillColor(sf::Color::Yellow);
    cercle.setPosition(FX/2-100, FY/2-100);
    cercle.setOutlineColor(sf::Color::Black);
    cercle.setOutlineThickness(2);
    Base.setFillColor(sf::Color::White);
    Base.setSize(sf::Vector2f(FX, FY));


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(Base);
        window.draw(cercle);
        window.display();
        window.clear();
    }

    return 0;
}