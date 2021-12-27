#include "sprites.h"

void SpritesClass::draw(RenderWindow& window)
{
	Vector2f center = window.getView().getCenter(), size = window.getView().getSize();
	sprite.setPosition(center.x - size.x / 2 + x, center.y - size.y / 2 + y);
	window.draw(sprite);
}
void SpritesClass::drawWorld(RenderWindow& window)
{
	sprite.setPosition(x, y);
	window.draw(sprite);
}
void SpritesClass::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
void SpritesClass::setOrigin(int x, int y)
{
	sprite.setOrigin(x, y);
}
void SpritesClass::setOriginInMiddle()
{
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}
void SpritesClass::setScale(float x, float y)
{
	sprite.setScale(x, y);
}
