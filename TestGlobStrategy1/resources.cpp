#include "resources.h"

Resource::Resource()
{
	x = 0;
	y = 0;
	name = "NO_NAME";
}
Resource::Resource(string name, int x, int y, string faction_owner, string city, int resource_left, int workers, int batche)
{
	this->x = x;
	this->y = y;
	this->name = name;
	sFactionOwner = faction_owner;
	iResourceLeft = resource_left;
	sCity = city;
	iWorkers = workers;
	iBatcheScale = batche;
	iDay = 5;
}
string Resource::getOwner()
{
	return sFactionOwner;
}
string Resource::getCity()
{
	return sCity;
}
int Resource::getResourceCount()
{
	return iResourceLeft;
}
int Resource::getWorkers()
{
	return iWorkers;
}
int Resource::getBactheScale()
{
	return iBatcheScale;
}
int Resource::getDay()
{
	return iDay;
}