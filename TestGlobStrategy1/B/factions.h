#pragma once
#include "iostream"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Faction
{
public:
	int money, peasants_taxes, priests_taxes;
	string name, culture;
	Faction();
	Faction(string name, string culture);
};
