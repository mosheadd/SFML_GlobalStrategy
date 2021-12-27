#pragma once
#include "iostream"
#include "fstream"
#include "vector"
#include "sprites.h"
#include "texts.h"
#include "factions.h"
#include "player.h"
#include "pugixml.hpp"
#include <tchar.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
using namespace pugi;
Player player;
vector<Faction> factionsList;
int mainmenu(RenderWindow& window)
{
	int factionsCount = 1;
	cout << "---------------FACTIONS---------------" << endl;
	xml_document factions;
	if (!factions.load_file("GameData\\Scenarios\\Main\\factions.xml")) cout << "Error: Factions.xml can not be loaded" << endl;
	xml_node factionsRoot = factions.child("Factions");
	cout << factionsRoot.name()<<endl;
	for (xml_node factionInfo = factionsRoot.first_child(); factionInfo; factionInfo = factionInfo.next_sibling())
	{
		cout << "FACTION " << factionsCount << endl;
		Faction faction;
		cout << factionInfo.name() << endl;
		cout << factionInfo.first_child().child_value() <<" "<<factionInfo.child("Culture").child_value()<< " " << factionInfo.child("StartMoney").child_value()<<
			" " << factionInfo.child("FormOfGovernement").child_value() << " " << factionInfo.child("CommunalSystem").child_value() << endl;
		faction.name = factionInfo.first_child().child_value();
		faction.culture = factionInfo.child("Culture").child_value();
		faction.money = stoi(factionInfo.child("StartMoney").child_value());
		faction.form_of_governement = factionInfo.child("FormOfGovernement").child_value();
		faction.communal_system = factionInfo.child("CommunalSystem").child_value();
		faction.peasants_taxes = 5;
		faction.priests_taxes = 5;
		faction.citizens_taxes = 5;
		faction.quitrent = 10;
		factionsList.push_back(faction);
		factionsCount++;
	}
	vector<Text> factionsTextsList;
	string str;
	Font font;
	font.loadFromFile("D:\\P2\\Enchanted Land.otf");
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
		Event event2;
		while (window.pollEvent(event2))
		{
			if (event2.type == Event::Closed)
				window.close();
		}
		if (Screen == 1)
		{
			if (IntRect(870, 600, 200, 63).contains(Mouse::getPosition(window)))
			{
				quit.setColor(Color::Red);
				ChoosedOption = 2;
			}
			else if (IntRect(893, 500, 155, 63).contains(Mouse::getPosition(window)))
			{
				play_campaign.setColor(Color::Red);
				ChoosedOption = 1;
			}
			else
			{
				play_campaign.setColor(Color::Black);
				quit.setColor(Color::Black);
				ChoosedOption = 0;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (ChoosedOption == 2) { return 0; }
				if (ChoosedOption == 1) { Screen = 2; }
			}
		}
		else if (Screen == 2)
		{
			if (IntRect(900, 800, 120, 63).contains(Mouse::getPosition(window)))
			{
				back.setColor(Color::Red);
				ChoosedOption = 3;
			}
			else
			{
				back.setColor(Color::Black);
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
					player.form_of_governement = factionsList[i].form_of_governement;
					player.communal_system = factionsList[i].communal_system;
					player.peasants_taxes = factionsList[i].peasants_taxes;
					player.priests_taxes = factionsList[i].priests_taxes;
					player.citizens_taxes = factionsList[i].citizens_taxes;
					player.quitrent = factionsList[i].quitrent;
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
				if (ChoosedOption == 2) { return 1; }
			}
		}
		window.clear();
		background.draw(window);
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
	return 0;
}
