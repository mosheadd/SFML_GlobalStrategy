#pragma once
#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class SpritesClass
{
public:
	Image image;
	Texture texture;
	Sprite sprite;
	int x, y;
	SpritesClass(string file)
	{
		image.loadFromFile("GameData\\Sprites\\" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		this->x = 0;
		this->y = 0;
	}
	SpritesClass(string file, int width, int height)
	{
		image.loadFromFile("GameData\\Sprites\\" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(width, height);
	}
	SpritesClass()
	{
	}
	///Рисует спрайт относительна окна
	void draw(RenderWindow& window);
	///Рисует спрайт в мире с закреплённми координатами
	void drawWorld(RenderWindow& window);
	void setPosition(int x, int y);
	void setOrigin(int x, int y);
	void setOriginInMiddle();
	void setScale(float x, float y);
};
