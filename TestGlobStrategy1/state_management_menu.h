#pragma once
#include"sprites.h"
#include"texts.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int state_managament_menu(RenderWindow& window)
{
	SpritesClass background("background.png");
	TextsClass quit("Quit", 40, 350, 605);
	TextsClass taxes("Taxes", 40, 165, 171);
	TextsClass back("Back", 40, 350, 560);
	TextsClass peasants("Peasants", 40, 191, 205);
	TextsClass priests("Priests", 40, 191, 308);
	TextsClass citizens("Citizens", 40, 191, 408);
	TextsClass quitrent("Quitrent", 40, 330, 205);
	TextsClass taxes_peasants_num(to_string(player.peasants_taxes), 45, 295, 201);
	TextsClass taxes_priests_num(to_string(player.priests_taxes), 45, 273, 304);
	TextsClass taxes_citizens_num(to_string(player.citizens_taxes), 45, 278, 404);
	TextsClass quitrent_num(to_string(player.quitrent), 45, 422, 205);
	TextsClass governement("Governement", 40, 465, 171);
	TextsClass form_of_governement("Form of governement:", 30, 165, 171);
	TextsClass current_form_of_governement(player.form_of_governement, 30, 345, 171);
	TextsClass communal_system("Communal system:", 32, 165, 210);
	TextsClass current_communal_system(player.communal_system, 30, 327, 210);
	background.sprite.setTextureRect(IntRect(0, 0, 500, 500));
	background.setOrigin(250, 250);
	background.setPosition(400, 400);
	Vector2i pixelPos;
	int choosed_option, screen = 0;
	bool isStateMenuOpened = true;
	cout << "State Menu Managment is opened" << endl;
	while (isStateMenuOpened)
	{
		Event event;
		choosed_option = 0;
		quit.setColor(Color::Black);
		quit.setColor(Color::Black);
		background.draw(window);
		if (screen == 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)) isStateMenuOpened = false;
			taxes.setColor(Color::Black);
			governement.setColor(Color::Black);
			if (IntRect(840, 830, 118, 42).contains(Mouse::getPosition(window)))
			{
				quit.setColor(Color::Red);
				choosed_option = 1;
			}
			else if (IntRect(394, 249, 158, 42).contains(Mouse::getPosition(window)))
			{
				taxes.setColor(Color::Red);
				choosed_option = 2;
			}
			else if (IntRect(1120, 250, 339, 42).contains(Mouse::getPosition(window)))
			{
				governement.setColor(Color::Red);
				choosed_option = 3;
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
						else if (choosed_option == 3) screen = 2;
						cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
						cout << "MOUSE_POSITION_SCREEN: " << pixelPos.x << " " << pixelPos.y << endl;
					}
				}
			}
			taxes.draw(window);
			governement.draw(window);
		}
		else if (screen == 1)
		{
			back.setColor(Color::Black);
			taxes_peasants_num.setColor(Color::Black);
			taxes_priests_num.setColor(Color::Black);
			taxes_citizens_num.setColor(Color::Black);
			quitrent_num.setColor(Color::Black);
			if (Keyboard::isKeyPressed(Keyboard::Escape)) isStateMenuOpened = false;
			if (IntRect(840, 830, 118, 42).contains(Mouse::getPosition(window)))
			{
				quit.setColor(Color::Red);
				choosed_option = 1;
			}
			else if (IntRect(840, 770, 118, 42).contains(Mouse::getPosition(window)))
			{
				back.setColor(Color::Red);
				choosed_option = 2;
			}
			else if (IntRect(700, 295, 27, 55).contains(Mouse::getPosition(window)))
			{
				taxes_peasants_num.setColor(Color::Red);
				choosed_option = 3;
			}
			else if (IntRect(653, 434, 27, 55).contains(Mouse::getPosition(window)))
			{
				taxes_priests_num.setColor(Color::Red);
				choosed_option = 4;
			}
			else if (IntRect(662, 571, 27, 46).contains(Mouse::getPosition(window)))
			{
				taxes_citizens_num.setColor(Color::Red);
				choosed_option = 5;
			}
			else if (IntRect(1014, 303, 27, 46).contains(Mouse::getPosition(window)))
			{
				quitrent_num.setColor(Color::Red);
				choosed_option = 6;
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
						else if (choosed_option == 5)
						{
							player.citizens_taxes += 1;
							taxes_citizens_num.text.setString(to_string(player.citizens_taxes));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].citizens_taxes += 1;
							}
						}
						else if (choosed_option == 6)
						{
							player.quitrent += 1;
							quitrent_num.text.setString(to_string(player.quitrent));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].quitrent += 1;
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
						else if (choosed_option == 5 && player.citizens_taxes > 1)
						{
							player.citizens_taxes -= 1;
							taxes_citizens_num.text.setString(to_string(player.citizens_taxes));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].citizens_taxes -= 1;
							}
						}
						else if (choosed_option == 6 && player.quitrent > 1)
						{
							player.quitrent -= 1;
							quitrent_num.text.setString(to_string(player.quitrent));
							for (int i = 0; i < factionsList.size(); i++)
							{
								if (player.name == factionsList[i].name)
									factionsList[i].quitrent -= 1;
							}
						}
					}
				}
			}
			back.draw(window);
			peasants.draw(window);
			priests.draw(window);
			citizens.draw(window);
			quitrent.draw(window);
			taxes_peasants_num.draw(window);
			taxes_priests_num.draw(window);
			taxes_citizens_num.draw(window);
			quitrent_num.draw(window);
		}
		else if (screen == 2)
		{
			back.setColor(Color::Black);
			if (IntRect(840, 830, 118, 42).contains(Mouse::getPosition(window)))
			{
				quit.setColor(Color::Red);
				choosed_option = 1;
			}
			else if (IntRect(840, 770, 118, 42).contains(Mouse::getPosition(window)))
			{
				back.setColor(Color::Red);
				choosed_option = 2;
			}
			while (window.pollEvent(event))
			{
				window.setKeyRepeatEnabled(false);
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)
				{
					pixelPos = Mouse::getPosition(window);
					if (choosed_option == 1) isStateMenuOpened = false;
					else if (choosed_option == 2) screen = 0;
					cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
					cout << "MOUSE_POSITION_SCREEN: " << pixelPos.x << " " << pixelPos.y << endl;
				}
			}
			back.draw(window);
			form_of_governement.draw(window);
			current_form_of_governement.draw(window);
			communal_system.draw(window);
			current_communal_system.draw(window);
		}
		quit.draw(window);
		window.display();
	}
	cout << "State Menu Managment is closed" << endl;
	return 0;
}