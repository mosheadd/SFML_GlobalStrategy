#pragma once
#include"sprites.h"
#include"texts.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int minor_menu(RenderWindow& window)
{
	bool isOpened = true;
	Vector2i pixelPos;
	SpritesClass background("minor_menu\\background_minor_menu.png", 90, 150);
	TextsClass continue_play("Continue", 35, 329, 256);
	TextsClass back_to_main_menu("Back to main menu", 35, 285, 300);
	TextsClass quit_thegame("Quit", 35, 345, 487);
	int choosed_option = 0, current_option;
	background.setPosition(370, 390);
	while (isOpened)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		continue_play.setColor(Color::Black);
		back_to_main_menu.setColor(Color::Black);
		quit_thegame.setColor(Color::Black);
		current_option = 0;
		if (IntRect(788, 360, 203, 35).contains(Mouse::getPosition(window)))
		{
			current_option = 1;
			continue_play.setColor(Color::Red);
		}
		else if (IntRect(820, 665, 110, 35).contains(Mouse::getPosition(window)))
		{
			current_option = 2;
			quit_thegame.setColor(Color::Red);
		}
		else if (IntRect(678, 419, 420, 32).contains(Mouse::getPosition(window)))
		{
			current_option = 3;
			back_to_main_menu.setColor(Color::Red);
		}
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.key.code == Mouse::Left)
			{
				choosed_option = current_option;
				if(choosed_option != 0)
					isOpened = false;
				pixelPos = Mouse::getPosition(window);
				cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
				cout << "MOUSE_POSITION_SCREEN: " << pixelPos.x << " " << pixelPos.y << endl;
			}
		}
		background.draw(window);
		continue_play.draw(window);
		back_to_main_menu.draw(window);
		quit_thegame.draw(window);
		window.display();
	}
	return choosed_option;
}