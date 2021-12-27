#pragma once
#include "string"
#include "objects.h"
#include <SFML/Graphics.hpp>

using namespace std;
class Resource : public Objects
{
private:
	int iResourceLeft, iWorkers, iBatcheScale, iDay;
	string sFactionOwner, sCity;
public:
	Resource();
	Resource(string name, int x, int y, string faction_owner, string city, int resource_left, int workers, int batche);
	/**
	* @return Имя ресурса
	*/
	string getOwner();
	string getCity();
	int getResourceCount();
	int getWorkers();
	int getBactheScale();
	int getDay();
};