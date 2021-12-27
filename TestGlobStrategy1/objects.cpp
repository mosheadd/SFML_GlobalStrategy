#include "objects.h"

int* Objects::getCoords()
{
	int coordinates[2] = { x,y };
	return coordinates;
}
string Objects::getName()
{
	return name;
}