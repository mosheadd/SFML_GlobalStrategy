#pragma once
#include "iostream"
#include "sprites.h"
#include "texts.h"
#include "buildings.h"
#include "vector"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void draw_city_ui(RenderWindow& window, string cityName, string cityLevel, vector<Buildings> cityBuildings)
{
	Vector2i pixelPos;
	bool isCityUiOpened = true;
	int choosedOption =0, buildingX, buildingY, screen = 1;
	SpritesClass city_ui("cities\\test_fig_znaet_kakoi_uzhe.png");
	SpritesClass city_ui_info("cities\\full_info.png");
	SpritesClass city_ui_level("cities\\levels\\" + cityLevel + ".png");
	TextsClass city_text_quit("Quit", 45, 393, 727);
	TextsClass city_text_name(cityName, 24, 391, 137);
	TextsClass city_text_info("Full Info", 65, 115, 475);
	TextsClass city_text_production("Production", 65, 295, 580);
	TextsClass city_text_governence("Governence", 65, 515, 475);
	TextsClass city_text_back("Back", 45, 393, 727);
	city_text_quit.setOriginInMiddle();
	city_text_back.setOriginInMiddle();
	city_text_name.setOriginInMiddle();
	city_ui.setPosition(40, 135);
	city_ui_info.setPosition(40, 135);
	city_ui_level.setPosition(98, 211);
	while (isCityUiOpened)
	{
		Event event;
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
					cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
					cout << "MOUSE_POSITION_SCREEN: " << pixelPos.x << " " << pixelPos.y << endl;
					if (screen == 1)
					{
						if (choosedOption == 1) isCityUiOpened = false;
						else if (choosedOption == 2) screen = 2;
					}
					else if (screen == 2)
					{
						if (choosedOption == 1) screen = 1;
					}
				}
			}
		}
		if (screen == 1)
		{
			choosedOption = 0;
			city_text_quit.setColor(Color::Black);
			city_text_info.setColor(Color::Black);
			if (IntRect(664, 965, 690, 75).contains(Mouse::getPosition(window)))
			{
				city_text_quit.setColor(Color::Red);
				choosedOption = 1;
			}
			else if (IntRect(275, 669, 482, 65).contains(Mouse::getPosition(window)))
			{
				city_text_info.setColor(Color::Red);
				choosedOption = 2;
			}
			city_ui.draw(window);
			buildingX = 245;
			buildingY = 180;
			for (int cityBuildingInd = 0; cityBuildingInd < cityBuildings.size(); cityBuildingInd++)
			{
				SpritesClass buildingIcon("buildings\\" + cityBuildings[cityBuildingInd].name + ".png");
				buildingIcon.setPosition(buildingX, buildingY);
				buildingIcon.draw(window);
				buildingX += 96;
			}
			city_ui_level.draw(window);
			city_text_quit.draw(window);
			city_text_name.draw(window);
			city_text_info.draw(window);
			city_text_production.draw(window);
			city_text_governence.draw(window);
		}
		else if (screen == 2)
		{
			city_text_back.setColor(Color::Black);
			if (IntRect(664, 965, 690, 75).contains(Mouse::getPosition(window)))
			{
				city_text_back.setColor(Color::Red);
				choosedOption = 1;
			}
			city_ui_info.draw(window);
			city_text_back.draw(window);
		}
		window.display();
	}
}