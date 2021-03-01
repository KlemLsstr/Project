#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Shape.h"

#pragma region variables

sf::RenderWindow window; //Fenetre
sf::RectangleShape Base; //Fond blanc
sf::RectangleShape rec; //rectangle
sf::CircleShape cercle;
sf::Vector2i PosSouris;
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

    rec = rect((FX / 2)-25, ((FY / 2 ) - 12.5) + 100 , 50, 25);
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineColor(sf::Color(100, 100, 100));
    rec.setOutlineThickness(2);

    cercle = cer(FX / 2 - 1, FY / 2 - 1, 1, 1000);
    cercle.setFillColor(sf::Color::Black);

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
        window.draw(rec);
        //window.draw(milieu);
        window.display();
        window.clear();
    }

    return 0;
}

void gestion_clavier() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rec.move(0, -1);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rec.move(0, 1);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rec.move(1, 0);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rec.move(-1, 0);
    }
}

void gestion_souris() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        PosSouris = sf::Mouse::getPosition(window);

        //rec.setPosition(PosSouris.x - 25, PosSouris.y - 12.5);                                                                          //place le rectangle la ou on clique.
        //std::cout << "Pos rectangle x: " << rec.getPosition().x << " Pos rectangle y: " << rec.getPosition().y << std::endl;            //Donne les positions du rectangle.
        //std::cout << "Pos souris x: " << PosSouris.x << " Pos souris y: " << PosSouris.y << std::endl;                                  //Donne les positions de la souris

        if (PosSouris.x >= rec.getPosition().x && PosSouris.x <= rec.getPosition().x + 50 && PosSouris.y >= rec.getPosition().y && PosSouris.y <= rec.getPosition().y + 25) {
            std::cout << "Bienjouer" << std::endl;                                                                                        //Si l'utilisateur clique sur le rectangle (bouton) sa fait la suite....
            do {
                rec.setFillColor(sf::Color(202, 202, 202, 190));
                rec.setOutlineColor(sf::Color::Black);
                rec.setOutlineThickness(3);
                window.clear();
                window.draw(rec);
            } while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
            rec.setFillColor(sf::Color::Transparent);
            rec.setOutlineColor(sf::Color(100, 100, 100));
            rec.setOutlineThickness(2);
            window.clear();
            window.draw(rec);
        }
    }
}
