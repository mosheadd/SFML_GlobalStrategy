#include "texts.h"

void TextsClass::draw(RenderWindow &window)
{
	Vector2f center = window.getView().getCenter(), size = window.getView().getSize();
	text.setPosition(center.x - size.x / 2 + x, center.y - size.y / 2 + y);
	window.draw(text);
}
void TextsClass::setOrigin(int x, int y)
{
	text.setOrigin(x, y);
}
void TextsClass::setOriginInMiddle()
{
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}
void TextsClass::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}
void TextsClass::setColor(Color color)
{
	text.setFillColor(color);
}
int TextsClass::getPositionX()
{
	return x;
}
int TextsClass::getPositionY()
{
	return y;
}
float TextsClass::getWidth()
{
	return text.getLocalBounds().width;
}
float TextsClass::getHeight()
{
	return text.getLocalBounds().height;
}