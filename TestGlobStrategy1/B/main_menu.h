#include "iostream"
#include "fstream"
#include "vector"
#include "sprites.h"
#include "texts.h"
#include "factions.h"
#include "player.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
Player player;
vector<Faction> factionsList;
void mainmenu(RenderWindow& window)
{
	ifstream file_factions("D:\\P2\\GameData\\Factions\\factions.txt");
	vector<Text> factionsTextsList;
	string str;
	Font font;
	font.loadFromFile("D:\\P2\\Enchanted Land.otf");
	int count;
	while (!file_factions.eof())
	{
		count = 0;
		getline(file_factions, str);
		if (str[0] != '0')
		{
			Faction faction;
			for (int i = 0; i < str.size(); i++)
			{
				string buf = "";
				while (str[i] != ',' && i < str.size())
				{
					buf += str[i];
					i++;
				}
				if (count == 0) faction.name = buf;
				else if (count == 1) faction.culture = buf;
				else if (count == 2) faction.money = stoi(buf);
				count++;
				cout << buf << " ";
			}
			cout << endl;
			faction.peasants_taxes = 5;
			faction.priests_taxes = 5;
			factionsList.push_back(faction);
		}
	}
	file_factions.close();
	SpritesClass background("background.png");
	TextsClass quit("Quit the game", 55, 870, 600);
	TextsClass play_campaign("Campaign", 55, 893, 500);
	TextsClass back("Back", 55, 900, 800);
	TextsClass culture("", 45, 1350, 130);
	TextsClass nameFaction("", 45, 1350, 80);
	//cout << factionsList.size() << endl;
	int x = 880, y = 200;
	for (int i = 0; i < factionsList.size(); i++)
	{
		factionsTextsList.push_back(Text(factionsList[i].name, font, 40));
		factionsTextsList[i].setPosition(x, y);
		factionsTextsList[i].setFillColor(Color::Black);
		y += 45;
	}
	//cout << factionsTextsList.size() << endl;
	//for (int i = 0; i < factionsTextsList.size(); i++) cout << factionsTextsList[i].text << endl;
	int ChoosedOption = 0, Screen = 1;
	bool isMenu = true, isFactionTextPressed = false;
	while (isMenu)
	{
		//cout << factionsTextsList.size() << endl;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Screen == 1)
		{
			if (IntRect(870, 600, 200, 63).contains(Mouse::getPosition(window)))
			{
				quit.text.setFillColor(Color::Red);
				ChoosedOption = 2;
			}
			else if (IntRect(893, 500, 155, 63).contains(Mouse::getPosition(window)))
			{
				play_campaign.text.setFillColor(Color::Red);
				ChoosedOption = 1;
			}
			else
			{
				play_campaign.text.setFillColor(Color::Black);
				quit.text.setFillColor(Color::Black);
				ChoosedOption = 0;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (ChoosedOption == 2) { window.close(); }
				if (ChoosedOption == 1) { Screen = 2; }
			}
		}
		else if (Screen == 2)
		{
			if (IntRect(900, 800, 120, 63).contains(Mouse::getPosition(window)))
			{
				back.text.setFillColor(Color::Red);
				ChoosedOption = 3;
			}
			else
			{
				back.text.setFillColor(Color::Black);
				ChoosedOption = 0;
			}
			for (int i = 0; i < factionsTextsList.size(); i++)
			{
				if (IntRect(factionsTextsList[i].getPosition().x, factionsTextsList[i].getPosition().y, 130, 42).contains(Mouse::getPosition(window)))
				{
					factionsTextsList[i].setFillColor(Color::Red);
					ChoosedOption = 2;
					isFactionTextPressed = true;
					nameFaction.text.setString(factionsList[i].name);
					culture.text.setString(factionsList[i].culture);
					player.name = factionsList[i].name;
					player.culture = factionsList[i].culture;
					player.money = factionsList[i].money;	
					player.peasants_taxes = 5;
					player.priests_taxes = 5;
				}
				else
				{
					factionsTextsList[i].setFillColor(Color::Black);					
				}
			}
			if (isFactionTextPressed == false)
			{
				ChoosedOption = 0;
				culture.text.setString("");
				nameFaction.text.setString("");
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (ChoosedOption == 3) { Screen = 1; }
				if (ChoosedOption == 2) { isMenu = false; }
			}
		}
		window.clear();
		window.draw(background.sprite);
		if (Screen == 1)
		{
			window.draw(quit.text);
			window.draw(play_campaign.text);
		}
		else if (Screen == 2)
		{
			for (int i = 0; i < factionsTextsList.size(); i++)
			{
				window.draw(factionsTextsList[i]);
			}
			window.draw(back.text);
			window.draw(nameFaction.text);
			window.draw(culture.text);
		}
		window.display();
	}
}