#pragma once
#include "string"
#include <SFML/Graphics.hpp>

using namespace std;
class Character
{
	string name, post;
public:
	Character();
	string getName();
	string getPost();
};