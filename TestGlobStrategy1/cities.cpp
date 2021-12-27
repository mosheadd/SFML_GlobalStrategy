#pragma once
#include "cities.h"
#include "texts.h"
#include "sprites.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void Cities::draw_hud(RenderWindow& window)
{
	SpritesClass city_ui("cities\\ui_city_test2.png");
	SpritesClass city_ui_name("cities\\ui_city_name.png");
	city_ui.setPosition(0, 675);
	city_ui_name.setPosition(310, 655);
	city_ui.draw(window);
	city_ui_name.draw(window);
}
void Cities::setLevel(string next_level)
{
	level = next_level;
}
bool Cities::clicked(float x, float y)
{

	if (x > this->x - 10 && y > this->y && x < this->x + 10 && y < this->y) 
		return true;

	return false;
}