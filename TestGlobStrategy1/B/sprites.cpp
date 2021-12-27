#include "sprites.h"

void SpritesClass::draw(RenderWindow& window)
{
	Vector2f center = window.getView().getCenter(), size = window.getView().getSize();
	sprite.setPosition(center.x - size.x / 2 + x, center.y - size.y / 2 + y);
	window.draw(sprite);
}
void SpritesClass::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}