#include "texts.h"

void TextsClass::draw(RenderWindow &window)
{
	Vector2f center = window.getView().getCenter(), size = window.getView().getSize();
	text.setPosition(center.x - size.x / 2 + x, center.y - size.y / 2 + y);
	window.draw(text);
}
int TextsClass::getPositionX()
{
	return x;
}
int TextsClass::getPositionY()
{
	return y;
}