#pragma once
#include "string"
#include <SFML/Graphics.hpp>

using namespace std;
class Districts
{
public:
	int population, peasants, workers, citizens, nobles, priests, food;
	string faction_name;
	Districts();
};