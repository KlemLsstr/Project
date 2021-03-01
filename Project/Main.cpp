#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Shape.h"

#pragma region variables

sf::RenderWindow window;

sf::RectangleShape Base;
sf::RectangleShape rec1;
sf::CircleShape milieu;

sf::Vector2i PosSouris;
sf::Vector2f PosRec;

int FX = 960, FY = 540;   //taille fenêtre en X et Y


#pragma endregion varaibles

#pragma region entêtes

void gestion_clavier();
void gestion_souris();

#pragma endregion entêtes




int main(){
    window.create(sf::VideoMode(FX, FY), "Project Programmation");
    window.setFramerateLimit(144);

    std::cout << "Lancement du jeu" << std::endl;

    Base.setFillColor(sf::Color::White);
    Base.setSize(sf::Vector2f(FX, FY));

    rec1 = rect((FX / 2)-25, ((FY / 2 ) - 12.5) + 100 , 50, 25);
    rec1.setFillColor(sf::Color::Transparent);
    rec1.setOutlineColor(sf::Color(0, 0, 0));
    rec1.setOutlineThickness(2);

    milieu = cer(FX / 2 - 1, FY / 2 - 1, 1, 1000);
    milieu.setFillColor(sf::Color::Black);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        gestion_clavier();
        gestion_souris();

        window.draw(Base);
        window.draw(rec1);
        //window.draw(milieu);
        window.display();
        window.clear();
    }

    return 0;
}

void gestion_clavier() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rec1.move(0, -1);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rec1.move(0, 1);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rec1.move(1, 0);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rec1.move(-1, 0);
    }
}

void gestion_souris() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        PosSouris = sf::Mouse::getPosition(window);
        //rec1.setPosition(PosSouris.x - 100, PosSouris.y - 50);

        PosRec = rec1.getPosition();
        //std::cout << "Pos rectangle x: " << PosRec.x << " Pos rectangle y: " << PosRec.y << std::endl;
        //std::cout << "Pos souris x: " << PosSouris.x << " Pos souris y: " << PosSouris.y << std::endl;
        if (PosSouris.x >= PosRec.x && PosSouris.x <= PosRec.x + 50 && PosSouris.y >= PosRec.y && PosSouris.y <= PosRec.y + 25) {
            std::cout << "Bienjouer" << std::endl;
        }
    }
}
