#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Menu.h"

#pragma region variables
sf::RenderWindow window;
int FX = 960, FY = 540;   //taille fenêtre en fonction de X et de Y

#pragma endregion varaibles

#pragma region entêtes

//sf::Vector2f gestion_clavier();
/*sf::RectangleShape gestion_clavier_rec(sf::RectangleShape _r);*/
//void gestion_souris();

#pragma endregion entêtes

int main(){
    Menu(window);
    return 0;
}

/*sf::Vector2f gestion_clavier() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        return sf::Vector2f(0, -1);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        return sf::Vector2f(0, 1);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        return sf::Vector2f(1, 0);
    }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        return sf::Vector2f(-1, 0);
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
            for (int i = 0; i <= 144 * 3; i++) {
                rec.setFillColor(sf::Color(202, 202, 202, 190));
                rec.setOutlineColor(sf::Color::Black);
                rec.setOutlineThickness(3);
                window.clear();
                window.draw(rec);
            }
            rec.setFillColor(sf::Color::Transparent);
            rec.setOutlineColor(sf::Color(100, 100, 100));
            rec.setOutlineThickness(2);
            window.clear();
            window.draw(rec);
        }
    }
}*/
