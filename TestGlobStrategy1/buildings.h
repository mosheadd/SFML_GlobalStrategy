#pragma once
#include "iostream"
#include "vector"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Buildings
{
public:
	string name, description, type;
	vector<string> work;
	Buildings();
	string getName();
	string getDescription();
	string getType();
	vector<string> getWork();
};