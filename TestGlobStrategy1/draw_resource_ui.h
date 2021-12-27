#pragma once
#include "iostream"
#include "sprites.h"
#include "texts.h"
#include "buildings.h"
#include "vector"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
void draw_resource_ui(RenderWindow&window, string sResourceName, string sResourceSpritePath, string sFactionOwner, string sCityName, int iMenWorking, int iResourceLeft, int iBatcheScale, int iDay)
{
	Vector2i pixelPos;
	Event event;
	int iChoosedOption = 0;
	bool isResourceUiOpened = true;
	SpritesClass resource_ui("resource_ui.png");
	SpritesClass resource_ui_icon(sResourceSpritePath);
	TextsClass resource_text_quit("Quit", 34, 400, 612);
	TextsClass resource_text_name(sResourceName, 43, 244, 190);
	TextsClass resource_text_owner(sFactionOwner, 43, 548, 190);
	TextsClass resource_text_workers("Men working:", 51, 264, 300);
	TextsClass resource_text_resource_left("Resource left:", 51, 374, 367);
	TextsClass resource_text_city("City:", 51, 312, 429);
	TextsClass resource_text_batche("Batche scale:", 51, 373, 459);
	TextsClass resource_text_workers_count(to_string(iMenWorking), 51, 372, 367 + resource_text_resource_left.getHeight());
	TextsClass resource_text_city_name(sCityName, 43, 351, 418);
	TextsClass resource_text_resource_left_count(to_string(iResourceLeft), 43, 474, 355);
	resource_ui.setPosition(150, 150);
	resource_ui_icon.setScale(2.425f, 2.425f);
	resource_ui_icon.setOriginInMiddle();
	resource_ui_icon.setPosition(470, 289);
	resource_text_quit.setOriginInMiddle();
	resource_text_name.setOriginInMiddle();
	resource_text_owner.setOriginInMiddle();
	while (isResourceUiOpened)
	{
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
					if (iChoosedOption == 1) isResourceUiOpened = false;
				}
			}
		}
		iChoosedOption = 0;
		resource_text_quit.setColor(Color::Black);
		if (IntRect(818, 828, 295, 30).contains(Mouse::getPosition(window)))
		{
			resource_text_quit.setColor(Color::Red);
			iChoosedOption = 1;
		}
		resource_ui.draw(window);
		resource_ui_icon.draw(window);
		resource_text_quit.draw(window);
		resource_text_name.draw(window);
		resource_text_owner.draw(window);
		resource_text_workers.draw(window);
		resource_text_workers_count.draw(window);
		/*resource_text_resource_left.draw(window);
		resource_text_city.draw(window);
		resource_text_batche.draw(window);
		resource_text_workers_count.draw(window);
		resource_text_city_name.draw(window);
		resource_text_resource_left_count.draw(window);*/
		window.display();
	}
}