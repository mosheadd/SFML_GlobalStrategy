#pragma once
#include "iostream"
#include "factions.h"
#include <SFML/Graphics.hpp>
#include "buildings.h"

using namespace std;
using namespace sf;

Buildings::Buildings()
{
}
string Buildings::getDescription()
{
	return description;
}
string Buildings::getName()
{
	return name;
}
string Buildings::getType()
{
	return type;
}
vector<string> Buildings::getWork()
{
	return work;
}