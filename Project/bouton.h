#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>


class Bouton {
public:
	Bouton(){}

	Bouton(std::string t, sf::Vector2f size,int charSize, sf::Color bgColor, sf::Color textColor, sf::Color Contour, int eTour) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);
		
		Button.setSize(size);
		Button.setFillColor(bgColor);
		Button.setOutlineColor(Contour);
		Button.setOutlineThickness(eTour);

	}

	void setFont(sf::Font& font) {
		text.setFont(font);
	}

	void setBackColor(sf::Color color) {
		Button.setFillColor(color);
	}

	void setTextColor(sf::Color color) {
		text.setFillColor(color);
	}

	void setPosition(sf::Vector2f pos) {
		Button.setPosition(pos);

		float xPos = (pos.x + Button.getGlobalBounds().width / 2.625) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + Button.getGlobalBounds().height / 3.5) - (text.getGlobalBounds().height / 2);
		text.setPosition(xPos, yPos);
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(Button);
		window.draw(text);
	}

	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = Button.getPosition().x;
		float btnPosY = Button.getPosition().y;

		float btnxPosWidth = Button.getPosition().x + Button.getLocalBounds().width;
		float btnyPosHeight = Button.getPosition().y + Button.getLocalBounds().height;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;
	}

private:
	sf::RectangleShape Button;
	sf::Text text;

};