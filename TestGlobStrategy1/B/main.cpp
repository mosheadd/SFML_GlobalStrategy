#include "iostream"
#include "main_menu.h"
#include "minor_menu.h"
#include "create_campmap.h"
#include "state_management_menu.h"
#include "tiles.h"
#include "cities.h"
#include "texts.h"
#include "sprites.h"
#include "cam.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(1920, 1080), "TGS1", Style::Fullscreen);
	view.reset(FloatRect(0, 0, 800, 800));
	mainmenu(window);
	campaignMapCreate();
	TilesClass grass("grass.png");
	grass.sprite.setTextureRect(IntRect(0, 0, 32, 32));
	TextsClass cam_x("", 30, 340, 0);
	TextsClass cam_y("", 30, 380, 0);
	TextsClass city_name("", 26, 378, 665);
	TextsClass city_population("", 33, 25, 665);
	TextsClass city_food("", 33, 117, 665);
	TextsClass city_growth("", 33, 30, 700);
	TextsClass city_birth_rate("", 33, 30, 735);
	TextsClass city_death_rate("", 33, 30, 763);
	TextsClass city_type("", 35, 186, 664);
	TextsClass city_income("", 35, 93, 705);
	TextsClass player_money("", 36, 5, 5);
	cam_x.text.setFillColor(Color::White);
	cam_y.text.setFillColor(Color::White);
	SpritesClass city("cities\\city.png", 10, 10);
	SpritesClass city_ui("cities\\ui_city_test.png");
	SpritesClass money_ui("cities\\ui_money_test.png");
	SpritesClass building_village("cities\\types\\village.png");
	SpritesClass building_town("cities\\types\\town.png");
	SpritesClass building_city("cities\\types\\city.png");
	SpritesClass building_big_city("cities\\types\\big_city.png");
	SpritesClass managment_frame("ui_campaign\\managment_icon_frame.png");
	SpritesClass managment_icon("ui_campaign\\managment_icon.png");
	city_ui.setPosition(0, 675);
	building_village.setPosition(196, 706);
	building_town.setPosition(196, 706);
	building_city.setPosition(196, 706);
	building_big_city.setPosition(196, 706);
	managment_frame.setPosition(764, 0);
	managment_icon.setPosition(765, 0);
	Vector2i pixelPos;
	Vector2f center, size, worldPos;
	cout << "------------PLAYER_INFORMATION------------" << endl;
	cout << player.name << " "<< player.culture <<" "<< player.money<<endl;
	int result_minor_menu = 0;
	bool is_mmenu_opened = false, clickOnCity = false, isManagmentMenuOpened = false;
	while (window.isOpen())
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
					worldPos = window.mapPixelToCoords(pixelPos);
				}
				cout << "MOUSE_POSITION_WORLD: " << worldPos.x << " " << worldPos.y << endl;
				cout << "MOUSE_POSITION_VIEW: " << pixelPos.x * 0.41666666666 << " " << pixelPos.y * 0.74074074074 << endl;
				if (pixelPos.x * 0.41666666666 >= 764 && pixelPos.y * 0.74074074074 <= 91) isManagmentMenuOpened = true;
			}
		}
		center = window.getView().getCenter();
		size = window.getView().getSize();
		player_money.text.setString(to_string(player.money));
		if (Keyboard::isKeyPressed(Keyboard::Escape)) is_mmenu_opened=true;
		if (is_mmenu_opened == false)
		{
			if (Keyboard::isKeyPressed(Keyboard::A)) go_left(0.2);
			if (Keyboard::isKeyPressed(Keyboard::W)) go_up(0.2);
			if (Keyboard::isKeyPressed(Keyboard::D)) go_right(0.2);
			if (Keyboard::isKeyPressed(Keyboard::S)) go_down(0.2);
			cam_x.text.setString(to_string((int)view.getCenter().x));
			cam_y.text.setString(to_string((int)view.getCenter().y));
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
		for (int i = 0; i < citiesList.size(); i++)
		{
			city.sprite.setPosition(citiesList[i].x, citiesList[i].y);
			window.draw(city.sprite);
			for (int j = 0; j < factionsList.size(); j++)
			{
				if(citiesList[j].faction_owner==factionsList[i].name)
					citiesList[i].income = ((citiesList[i].peasants + citiesList[i].workers) * factionsList[i].peasants_taxes) + citiesList[i].priests * factionsList[i].priests_taxes;
			}
			if (city.sprite.getGlobalBounds().contains(worldPos.x, worldPos.y))
			{
				//clickOnCity = true;
				city_name.text.setString(citiesList[i].name);
				city_population.text.setString(to_string(citiesList[i].population));
				city_food.text.setString(to_string(citiesList[i].food));
				city_growth.text.setString(to_string(citiesList[i].growth));
				city_birth_rate.text.setString(to_string(citiesList[i].birth_rate));
				city_death_rate.text.setString(to_string(citiesList[i].death_rate));
				city_type.text.setString(citiesList[i].type);
				city_income.text.setString(to_string(citiesList[i].income));
				city_ui.draw(window);
				city_name.draw(window);
				city_population.draw(window);
				city_food.draw(window);
				city_growth.draw(window);
				city_birth_rate.draw(window);
				city_death_rate.draw(window);
				city_type.draw(window);
				city_income.draw(window);
				if (citiesList[i].type == "village") building_village.draw(window);
				else if (citiesList[i].type == "town") building_town.draw(window);
				else if (citiesList[i].type == "city") building_city.draw(window);
				else if (citiesList[i].type == "big_city") building_big_city.draw(window);
			}
		}
		money_ui.draw(window);
		player_money.draw(window);
		managment_frame.draw(window);
		managment_icon.draw(window);
		cam_x.draw(window);
		cam_y.draw(window);
		if (isManagmentMenuOpened)
		{
			state_managament_menu(window);
			isManagmentMenuOpened = false;
		}
		if (is_mmenu_opened) result_minor_menu = minor_menu(window);
		if (result_minor_menu == 1) is_mmenu_opened = false;
		else if (result_minor_menu == 2) window.close();
		window.display();
	}
	return 0;
}