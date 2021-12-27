#pragma once
#include "iostream"
#include "vector"
#include "objects.h"
#include "factions.h" 
#include "buildings.h"
#include "map"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Cities : public Objects
{
public:
	map<string, int> populationList;
	map<string, int> resourcesList;
	vector<Buildings> buildings;
	int population, growth, birth_rate, death_rate, food, income;
	string faction_owner, level;
	void draw_hud(RenderWindow& window);
	/*Cities(string file)
	{
		object_sprite.image.loadFromFile("D:\\P2\\GameData\\Sprites\\" + file);
		object_sprite.texture.loadFromImage(object_sprite.image);
		object_sprite.sprite.setTexture(object_sprite.texture);
	}*/
	Cities()
	{
	}
	void setLevel(string next_level);
	bool clicked(float x, float y);
};