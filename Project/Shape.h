#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>


sf::RectangleShape rect(int X, int Y, int L, int l) {
	sf::RectangleShape rect(sf::Vector2f(L, l));
	rect.setPosition(X, Y);
	return rect;
}
sf::CircleShape cer(int X, int Y, int R, int C) {
	sf::CircleShape cercle(R, C);
	cercle.setPosition(X, Y);
	return cercle;
}
