#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

View view;
View move_cam(float speed_x, float speed_y)
{
	view.setCenter(view.getCenter().x + speed_x, view.getCenter().y + speed_y);
	return view;
}
View go_left(float speed)
{
	if (view.getCenter().x - view.getSize().x / 2 - speed > 0) view.setCenter(view.getCenter().x - speed, view.getCenter().y);
	return view;
}
View go_up(float speed)
{
	if (view.getCenter().y - view.getSize().y / 2 - speed > 0) view.setCenter(view.getCenter().x, view.getCenter().y - speed);
	return view;
}
View go_right(float speed)
{
	if (view.getCenter().x + view.getSize().x / 2 + speed < 1600) view.setCenter(view.getCenter().x + speed, view.getCenter().y);
	return view;
}
View go_down(float speed)
{
	if (view.getCenter().y + view.getSize().y / 2 + speed < 1600) view.setCenter(view.getCenter().x, view.getCenter().y + speed);
	return view;
}
View Changing()
{
	if (Keyboard::isKeyPressed(Keyboard::Subtract))
	{
		view.zoom(1.0010f);
	}
	return view;
}