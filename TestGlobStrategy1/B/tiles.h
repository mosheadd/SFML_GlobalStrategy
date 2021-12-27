#pragma once
#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class TilesClass
{
public:
	Image image;
	Texture texture;
	Sprite sprite;
	TilesClass(string file)
	{
		image.loadFromFile("D:\\P2\\GameData\\TilesMap\\" + file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}
};