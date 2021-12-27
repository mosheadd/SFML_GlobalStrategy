#pragma once
#include "iostream"
#include "vector"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Faction
{
public:
	int money, peasants_taxes, priests_taxes, citizens_taxes, quitrent;
	string name, culture, form_of_governement, communal_system;
	vector<string> buildingsPool;
	Faction();
	Faction(string name, string culture);
	string getName();
	string* getGovernement();
};
