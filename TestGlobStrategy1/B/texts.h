#pragma once
#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class TextsClass
{
public:
	Font font;
	Text text;
	int x, y;
	TextsClass(string text, int size, int x, int y)
	{
		font.loadFromFile("D:\\P2\\Enchanted Land.otf");
		this->text.setString(text);
		this->text.setFont(font);
		this->text.setCharacterSize(size);
		this->text.setFillColor(Color::Black);
		this->text.setPosition(x, y);
		this->x = x;
		this->y = y;
	}
	TextsClass()
	{
	}
	void draw(RenderWindow& window);
	int getPositionX();
	int getPositionY();
};