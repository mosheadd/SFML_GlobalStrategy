#pragma once
#include "iostream"
#include "objects.h"
#include "factions.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Cities : public Objects
{
public:
	int population, peasants, workers, nobles, priests, growth, birth_rate, death_rate, food, income;
	int buildings[10];
	string faction_owner, type;
	Faction faction_ownert;
	/*Cities(string file)
	{
		object_sprite.image.loadFromFile("D:\\P2\\GameData\\Sprites\\" + file);
		object_sprite.texture.loadFromImage(object_sprite.image);
		object_sprite.sprite.setTexture(object_sprite.texture);
	}*/
	Cities()
	{
	}
};