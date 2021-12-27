#include "iostream"
#include "sqlite3.h"
#include "main_menu.h"
#include "minor_menu.h"
#include "create_campmap.h"
#include "state_management_menu.h"
#include "tiles.h"
#include "cities.h"
#include "texts.h"
#include "sprites.h"
#include "cam.h"
#include "time.h"
#include "draw_city_ui.h"
#include "draw_resource_ui.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

bool clicked(float fObjX, float fObjY, float fMouseX, float fMouseY, float fRadiusX, float fRadiusY)
{

	if (fMouseX >= fObjX - fRadiusX && fMouseY >= fObjY - fRadiusY && fMouseX <= fObjX + fRadiusX && fMouseY <= fObjY + fRadiusY)
		return true;

	return false;

}

int hours = 1, days = 1, time_speed = 1;
int main()
{
	RenderWindow window(VideoMode(1920, 1080), "TGS1", Style::Fullscreen);
	view.reset(FloatRect(0, 0, 800, 800));
	TilesClass grass("grass.png");
	grass.sprite.setTextureRect(IntRect(0, 0, 32, 32));
	TextsClass cam_x("", 30, 10, 50);
	TextsClass cam_y("", 30, 50, 50);
	TextsClass player_money("", 36, 5, 5);
	TextsClass hours_title("Hours", 45, 260, 0);
	TextsClass hours_text("", 40, 347, 5);
	TextsClass hours_speed("1", 40, 397, 5);
	TextsClass days_title("Days", 45, 449, 0);
	TextsClass days_text("", 40, 519, 5);
	cam_x.setColor(Color::White);
	cam_y.setColor(Color::White);
	SpritesClass city("cities\\city.png", 10, 10);
	SpritesClass money_ui("cities\\ui_money_test.png");;
	SpritesClass managment_frame("ui_campaign\\managment_icon_frame.png");
	SpritesClass managment_icon("ui_campaign\\managment_icon.png");
	SpritesClass time_back("ui_campaign\\time_back.png");
	managment_frame.setPosition(764, 0);
	managment_icon.setPosition(765, 0);
	time_back.setPosition(250, 0);
	Vector2i pixelPos;
	Vector2f center, size, worldPos;
	cout << "------------PLAYER_INFORMATION------------" << endl;
	cout << player.name << " " << player.culture << " " << player.money << endl;
	int result_minor_menu = 0, hour_start = 0, hour_end;
	bool is_mmenu_opened = false, clickOnCity = false, isManagmentMenuOpened = false, isMainMenuOpened = true, isLMBClicked = false;
	while (window.isOpen())
	{
		Event event;
		pixelPos = Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			window.setKeyRepeatEnabled(false);
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					//pixelPos = Mouse::getPosition(window);
					if (hours_speed.x <= pixelPos.x * 0.41666666666 && hours_speed.x + 30 >= pixelPos.x * 0.41666666666 &&
						hours_speed.y <= pixelPos.y * 0.74074074074 && hours_speed.y + 50 >= pixelPos.y * 0.74074074074)
					{
						if (time_speed < 5)
						{
							time_speed++;
							hours_speed.text.setString(to_string(time_speed));
						}
					}
					worldPos = window.mapPixelToCoords(pixelPos);
					//if(clickOnCity != true || pixelPos.y <= 666) worldPos = window.mapPixelToCoords(pixelPos);
				}
				else if (event.key.code == Mouse::Right)
				{
					if (hours_speed.x <= pixelPos.x * 0.41666666666 && hours_speed.x + 30 >= pixelPos.x * 0.41666666666 &&
						hours_speed.y <= pixelPos.y * 0.74074074074 && hours_speed.y + 50 >= pixelPos.y * 0.74074074074)
					{
						if (time_speed > 1)
						{
							time_speed--;
							hours_speed.text.setString(to_string(time_speed));
						}
					}
				}
				cout << "MOUSE_POSITION_WORLD: " << worldPos.x << " " << worldPos.y << endl;
				cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
				if (pixelPos.x * 0.41666666666 >= 764 && pixelPos.y * 0.74074074074 <= 91) isManagmentMenuOpened = true;
			}

		}
		if (isMainMenuOpened)
		{
			int main_menu_choice = mainmenu(window);
			if (main_menu_choice == 1) campaignMapCreate();
			else if (main_menu_choice == 0) window.close();
			isMainMenuOpened = false;
		}
		if (hour_start == 0) hour_start = clock();
		hour_end = clock();
		hour_start = worlds_time(hour_start, hour_end, hours, days, time_speed)[0];
		hours = worlds_time(hour_start, hour_end, hours, days, time_speed)[1];
		days = worlds_time(hour_start, hour_end, hours, days, time_speed)[2];
		hours_text.text.setString(to_string(hours));
		days_text.text.setString(to_string(days));
		center = window.getView().getCenter();
		size = window.getView().getSize();
		player_money.text.setString(to_string(player.money));
		if (Keyboard::isKeyPressed(Keyboard::Escape)) is_mmenu_opened = true;
		if (is_mmenu_opened == false)
		{
			if (Keyboard::isKeyPressed(Keyboard::A)) go_left(0.2);
			if (Keyboard::isKeyPressed(Keyboard::W)) go_up(0.2);
			if (Keyboard::isKeyPressed(Keyboard::D)) go_right(0.2);
			if (Keyboard::isKeyPressed(Keyboard::S)) go_down(0.2);
			cam_x.text.setString(to_string((int)view.getCenter().x));
			cam_y.text.setString(to_string((int)view.getCenter().y));
		}
		hours_speed.setColor(Color::Black);
		if (hours_speed.x <= pixelPos.x * 0.41666666666 && hours_speed.x + 30 >= pixelPos.x * 0.41666666666 &&
			hours_speed.y <= pixelPos.y * 0.74074074074 && hours_speed.y + 50 >= pixelPos.y * 0.74074074074)
		{
			hours_speed.setColor(Color::Red);
		}
		window.setView(view);
		window.clear();
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (Map[i][j] == 0)
				{
					grass.sprite.setPosition(i * 32, j * 32);
					window.draw(grass.sprite);
				}
			}
		}
		for (int resourceInd = 0; resourceInd < resourcesList.size(); resourceInd++)
		{
			SpritesClass resource_sprite("resources\\" + resourcesList[resourceInd].getName() + ".png");
			resource_sprite.setOriginInMiddle();
			resource_sprite.setPosition(resourcesList[resourceInd].getCoords()[0], resourcesList[resourceInd].getCoords()[1]);
			resource_sprite.drawWorld(window);
		}
		for (int i = 0; i < citiesList.size(); i++)
		{
			city.setPosition(citiesList[i].x, citiesList[i].y);
			city.drawWorld(window);
		}
		money_ui.draw(window);
		player_money.draw(window);
		managment_frame.draw(window);
		managment_icon.draw(window);
		time_back.draw(window);
		hours_title.draw(window);
		hours_text.draw(window);
		hours_speed.draw(window);
		days_title.draw(window);
		days_text.draw(window);
		cam_x.draw(window);
		cam_y.draw(window);
		for (int i = 0; i < citiesList.size(); i++)
		{
			//cout << citiesList[i].x << " " << citiesList[i].y << " " << (int)worldPos.x << " " << (int)worldPos.y << endl;
			if (clicked(citiesList[i].x, citiesList[i].y, worldPos.x, worldPos.y, 10.0f, 10.0f))
			{
				draw_city_ui(window, citiesList[i].getName(), citiesList[i].level, citiesList[i].buildings);
				worldPos = {-1, -1};
			}
		}
		for (int i = 0; i < resourcesList.size(); i++)
		{
			if (clicked(resourcesList[i].x, resourcesList[i].y, worldPos.x, worldPos.y, 20.0f, 20.0f))
			{
				cout << resourcesList[i].x << " "<<resourcesList[i].y <<" "<< worldPos.x<<" "<< worldPos.y<<endl;
				draw_resource_ui(window, resourcesList[i].getName(), "resources\\" + resourcesList[i].getName() + ".png", resourcesList[i].getOwner(),
					resourcesList[i].getCity(), resourcesList[i].getWorkers(), resourcesList[i].getResourceCount(), resourcesList[i].getBactheScale(),
					resourcesList[i].getDay());
				worldPos = { -1, -1 };
			}
		}
		if (isManagmentMenuOpened)
		{
			state_managament_menu(window);
			isManagmentMenuOpened = false;
		}
		if (is_mmenu_opened) result_minor_menu = minor_menu(window);
		if (result_minor_menu == 1) is_mmenu_opened = false;
		else if (result_minor_menu == 2) window.close();
		else if (result_minor_menu == 3) isMainMenuOpened = true;
		window.display();
	}
	return 0;
}