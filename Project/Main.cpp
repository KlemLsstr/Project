#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#pragma region variables
sf::RenderWindow window;
sf::CircleShape cercle;
#pragma endregion varaibles


int main(){
    window.create(sf::VideoMode(800, 600), "Project Programmation");
    window.setFramerateLimit(144);

    std::cout << "Lancement du jeu" << std::endl;

    cercle.setFillColor(sf::Color(100, 250, 150));
    cercle.setRadius(100);
    cercle.setPosition(300, 200);
    cercle.setOutlineColor(sf::Color(100, 100, 100));
    cercle.setOutlineThickness(2);


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(cercle);
        window.display();
        window.clear();
    }

    return 0;
}