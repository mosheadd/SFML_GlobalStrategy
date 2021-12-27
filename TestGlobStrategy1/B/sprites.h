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
		image.loadFromFile("D:\\P2\\GameData\\Sprites\\" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		this->x = 0;
		this->y = 0;
	}
	SpritesClass(string file, int width, int height)
	{
		image.loadFromFile("D:\\P2\\GameData\\Sprites\\" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(width, height);
	}
	SpritesClass()
	{
	}
	void draw(RenderWindow& window);
	void setPosition(int x, int y);
};
