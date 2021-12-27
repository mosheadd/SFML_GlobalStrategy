#pragma once
#include "iostream"
#include <string>
#include "fstream"
#include "vector"
#include <sstream>
#include "cities.h"
#include "districts.h"
#include "buildings.h"
#include "resources.h"
#include "pugixml.hpp"

using namespace std;
using namespace pugi;
int Map[50][50];
vector<Cities> citiesList;
vector<Buildings> buildingsList;
vector<Resource> resourcesList;
void campaignMapCreate()
{

	ifstream file_maps("GameData\\Scenarios\\Main\\map_main.txt");
	string str;
	int countRows = 0;
	cout << "-----------------------MAP------------------------" << endl;
	while (!file_maps.eof())
	{
		int countCols = 0;
		getline(file_maps, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ',')
			{
				Map[countRows][countCols] = (int)str[i] - 48;
				countCols++;
				cout << str[i];
			}
		}
		cout << endl;
		countRows++;
	}
	cout << "--------------------END_OF_MAP--------------------" << endl;
	file_maps.close();
	cout << "--------------BUILDINGS--------------" << endl;
	xml_document buildings;
	if (!buildings.load_file("GameData\\Scenarios\\Main\\Buildings.xml")) cout << "Error: Buildings.xml can not be loaded" << endl;
	xml_node buildingsRoot = buildings.first_child();
	int buildingsCount = 1;
	for (xml_node buildingInfo = buildingsRoot.first_child(); buildingInfo; buildingInfo = buildingInfo.next_sibling())
	{
		cout << "BUILDING " << buildingsCount << endl;
		Buildings building;
		cout << buildingInfo.first_child().child_value() << " " << buildingInfo.child("Description").child_value() << " " << buildingInfo.child("Type").child_value() <<
			" " << buildingInfo.child("FactionsCanBuild").child_value() << " " << buildingInfo.child("Work").child_value() << endl;
		building.name = buildingInfo.first_child().child_value();
		building.description = buildingInfo.child("Description").child_value();
		building.type = buildingInfo.child("Type").child_value();
		string buildingWork = buildingInfo.child("Work").child_value(), workArgument;
		for (int buildingWork_char_index = 1; buildingWork_char_index < buildingWork.size(); buildingWork_char_index++)
		{
			while (buildingWork[buildingWork_char_index] != ',' && buildingWork[buildingWork_char_index] != ']' && buildingWork_char_index < buildingWork.size())
			{
				workArgument += buildingWork[buildingWork_char_index];
				buildingWork_char_index++;
			}
			cout << workArgument << endl;
			building.work.push_back(workArgument);
			workArgument = "";
		}
		string buildingFactions = buildingInfo.child("FactionsCanBuild").child_value(), buildingFaction;
		for (int buildingFactions_char_index = 1; buildingFactions_char_index < buildingFactions.size(); buildingFactions_char_index++)
		{
			while (buildingFactions[buildingFactions_char_index] != ',' && buildingFactions[buildingFactions_char_index] != ']' && buildingFactions_char_index < buildingFactions.size())
			{
				buildingFaction += buildingFactions[buildingFactions_char_index];
				buildingFactions_char_index++;
			}
			for (int factionIndex = 0; factionIndex < factionsList.size(); factionIndex++)
			{
				if (buildingFaction == factionsList[factionIndex].name) factionsList[factionIndex].buildingsPool.push_back(building.name);
			}
			cout << buildingFaction << endl;
			buildingFaction = "";
		}
		buildingsList.push_back(building);
		buildingsCount++;
	}
	cout << "----------CITIES_OF_THIS_SCENARIO----------" << endl;
	xml_document cities;
	if (!cities.load_file("GameData\\Scenarios\\Main\\Cities.xml")) cout << "Error: Cities.xml can not be loaded" << endl;
	xml_node citiesRoot = cities.first_child();
	int citiesCount=1;
	for (xml_node cityInfo = citiesRoot.first_child(); cityInfo; cityInfo = cityInfo.next_sibling())
	{
		cout << "CITY " << citiesCount << endl;
		Cities city;
		cout << cityInfo.first_child().child_value() << " " << cityInfo.child("XCoord").child_value() << " " << cityInfo.child("YCoord").child_value() << " " << cityInfo.child("FactionOwner").child_value()
			<< "\n" << cityInfo.child("Buildings").child_value() << " " << cityInfo.child("Population").child_value() <<" "<< cityInfo.child("Level").child_value() << endl;
		city.name = cityInfo.first_child().child_value();
		city.x = stoi(cityInfo.child("XCoord").child_value());
		city.y = stoi(cityInfo.child("YCoord").child_value());
		city.faction_owner = cityInfo.child("FactionOwner").child_value();
		city.food = stoi(cityInfo.child("Food").child_value());
		city.level = cityInfo.child("Level").child_value();
		string cityBuildings = cityInfo.child("Buildings").child_value(), cityBuilding;
		for (int cityBuildings_index = 1; cityBuildings_index < cityBuildings.size(); cityBuildings_index++)
		{
			while (cityBuildings[cityBuildings_index] != ',' && cityBuildings[cityBuildings_index] != ']' && cityBuildings_index != cityBuildings.size())
			{
				cityBuilding += cityBuildings[cityBuildings_index];
				cityBuildings_index++;
			}
			cout << cityBuilding << endl;
			for (int building_index = 0; building_index < buildingsList.size(); building_index++)
			{
				if (buildingsList[building_index].name == cityBuilding) city.buildings.push_back(buildingsList[building_index]);
			}
			cityBuilding = "";
		}
		string cityPopulation = cityInfo.child("Population").child_value(), cityEstate, estateCount;
		for (int cityPopulation_index = 1; cityPopulation_index < cityPopulation.size(); cityPopulation_index++)
		{
			while (cityPopulation[cityPopulation_index] != '=')
			{
				cityEstate += cityPopulation[cityPopulation_index];
				cityPopulation_index++;
			}
			cityPopulation_index++;
			while (cityPopulation[cityPopulation_index] != ']' && cityPopulation[cityPopulation_index] != ',' &&cityPopulation_index != cityPopulation.size())
			{
				estateCount += cityPopulation[cityPopulation_index];
				cityPopulation_index++;
			}
			cout << cityEstate << "=" << estateCount << endl;
			city.populationList[cityEstate] = stoi(estateCount);
			cityEstate = "";	
			estateCount = "";
		}
		citiesCount++;
		citiesList.push_back(city);
	}
	cout << "----------RESOURCES_OF_THIS_SCENARIO----------" << endl;
	xml_document resources;
	if (!resources.load_file("GameData\\Scenarios\\Main\\Resources.xml")) cout << "Error: Resources.xml can not be loaded" << endl;
	xml_node resourcesRoot = resources.first_child();
	for (xml_node resourceInfo = resourcesRoot.first_child(); resourceInfo; resourceInfo = resourceInfo.next_sibling())
	{
		cout << resourceInfo.child("Name").child_value() << " " << resourceInfo.child("XCoord").child_value() << " " 
			<< resourceInfo.child("YCoord").child_value() <<" "<< resourceInfo.child("Owner").child_value()<< endl;
		Resource resource(resourceInfo.child("Name").child_value(), stoi(resourceInfo.child("XCoord").child_value()), stoi(resourceInfo.child("YCoord").child_value()),
			resourceInfo.child("Owner").child_value(), resourceInfo.child("City").child_value(), stoi(resourceInfo.child("ResourceCount").child_value()), stoi(resourceInfo.child("Workers").child_value()),
			stoi(resourceInfo.child("Batche").child_value()));
		resourcesList.push_back(resource);
	}
}