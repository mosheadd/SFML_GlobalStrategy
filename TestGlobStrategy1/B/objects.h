#include "iostream"
#include "sprites.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Objects
{
public:
	SpritesClass object_sprite;
	float x, y;
	string name;
	Objects()
	{
		x = 0;
		y = 0;
	}
};