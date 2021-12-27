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