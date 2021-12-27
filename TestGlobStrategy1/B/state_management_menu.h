#pragma once
#include"sprites.h"
#include"texts.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int state_managament_menu(RenderWindow& window)
{
	Vector2i pixelPos;
	SpritesClass background("background.png");
	TextsClass quit("Quit", 40, 350, 605);
	TextsClass taxes("Taxes", 40, 165, 171);
	TextsClass back("Back", 40, 350, 560);
	TextsClass peasants("Peasants", 40, 191, 205);
	TextsClass priests("Priests", 40, 191, 308);
	TextsClass taxes_peasants_num(to_string(player.peasants_taxes), 45, 368, 201);
	TextsClass taxes_priests_num(to_string(player.priests_taxes), 45, 368, 304);
	background.sprite.setTextureRect(IntRect(0, 0, 500, 500));
	background.sprite.setOrigin(250, 250);
	background.setPosition(400, 400);
	int choosed_option, screen = 0;
	bool isStateMenuOpened = true;
	cout << "State Menu Managment is opened" << endl;
	while(isStateMenuOpened)
	{
		Event event;
		choosed_option = 0;
		quit.text.setFillColor(Color::Black);
		background.draw(window);
		if (screen == 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)) isStateMenuOpened = false;
			taxes.text.setFillColor(Color::Black);
			if (IntRect(840, 830, 118, 42).contains(Mouse::getPosition(window)))
			{
				quit.text.setFillColor(Color::Red);
				choosed_option = 1;
			}
			else if (IntRect(394, 249, 158, 42).contains(Mouse::getPosition(window)))
			{
				taxes.text.setFillColor(Color::Red);
				choosed_option = 2;
			}
			while (window.pollEvent(event))
			{
				window.setKeyRepeatEnabled(false);
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.key.code == Mouse::Left)
					{

						pixelPos = Mouse::getPosition(window);
						if (choosed_option == 1) isStateMenuOpened = false;
						else if (choosed_option == 2) screen = 1;
						cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
						cout << "MOUSE_POSITION_SCREEN: " << pixelPos.x << " " << pixelPos.y << endl;
					}
				}
			}
			taxes.draw(window);
		}
		else if (screen == 1)
		{
			back.text.setFillColor(Color::Black);
			taxes_peasants_num.text.setFillColor(Color::Black);
			taxes_priests_num.text.setFillColor(Color::Black);
			if (Keyboard::isKeyPressed(Keyboard::Escape)) isStateMenuOpened = false;
			if (IntRect(840, 830, 118, 42).contains(Mouse::getPosition(window)))
			{
				quit.text.setFillColor(Color::Red);
				choosed_option = 1;
			}
			else if (IntRect(840, 770, 118, 42).contains(Mouse::getPosition(window)))
			{
				back.text.setFillColor(Color::Red);
				choosed_option = 2;
			}
			else if (IntRect(884, 285, 27, 46).contains(Mouse::getPosition(window)))
			{
				taxes_peasants_num.text.setFillColor(Color::Red);
				choosed_option = 3;
			}
			else if (IntRect(884, 415, 27, 46).contains(Mouse::getPosition(window)))
			{
				taxes_priests_num.text.setFillColor(Color::Red);
				choosed_option = 4;
			}
			while (window.pollEvent(event))
			{
				window.setKeyRepeatEnabled(false);
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.key.code == Mouse::Left)
					{
						window.setKeyRepeatEnabled(false);
						pixelPos = Mouse::getPosition(window);
						if (choosed_option == 1) isStateMenuOpened = false;
						else if (choosed_option == 2) screen = 0;
						else if (choosed_option == 3)
						{
							player.peasants_taxes += 1;
							taxes_peasants_num.text.setString(to_string(player.peasants_taxes));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].peasants_taxes += 1;
							}
						}
						else if (choosed_option == 4)
						{
							player.priests_taxes += 1;
							taxes_priests_num.text.setString(to_string(player.priests_taxes));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].priests_taxes += 1;
							}
						}
						cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
						cout << "MOUSE_POSITION_SCREEN: " << pixelPos.x << " " << pixelPos.y << endl;
					}
					else if (event.key.code == Mouse::Right)
					{
						if (choosed_option == 3 && player.peasants_taxes > 1)
						{
							player.peasants_taxes -= 1;
							taxes_peasants_num.text.setString(to_string(player.peasants_taxes));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].peasants_taxes -= 1;
							}
						}
						else if (choosed_option == 4 && player.priests_taxes > 1)
						{
							player.priests_taxes -= 1;
							taxes_priests_num.text.setString(to_string(player.priests_taxes));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].priests_taxes -= 1;
							}
						}
					}
				}
			}
			back.draw(window);
			peasants.draw(window);
			priests.draw(window);
			taxes_peasants_num.draw(window);
			taxes_priests_num.draw(window);
		}
		quit.draw(window);
		window.display();
	}
	cout << "State Menu Managment is closed" << endl;
	return 0;
}