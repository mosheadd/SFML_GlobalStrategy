#include "iostream"
#include "factions.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
Faction::Faction()
{
}
Faction::Faction(string name, string culture)
{
	this->name = name;
	this->culture = culture;
}
string Faction::getName()
{
	return name;
}
string* Faction::getGovernement()
{
	string governement[2] = { form_of_governement, communal_system };
	return governement;
}