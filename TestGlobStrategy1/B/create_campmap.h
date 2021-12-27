#include "iostream"
#include <string>
#include "fstream"
#include "vector"
#include "cities.h"

using namespace std;
int Map[50][50];
vector<Cities> citiesList;
void campaignMapCreate()
{
	ifstream file_maps("D:\\P2\\GameData\\Maps\\Main\\map_main.txt");
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
	ifstream file_cities("D:\\P2\\GameData\\Maps\\Main\\cities.txt");
	cout << "----------CITIES_OF_THIS_MAP----------" << endl;
	int count;
	str = "";
	while (!file_cities.eof())
	{
		getline(file_cities, str);
		if (str[0] != '0')
		{
			Cities city;
			count = 0;
			for (int i = 0; i < str.size(); i++)
			{
				string buf = "";
				while (str[i] != ',' && i < str.size())
				{
					buf += str[i];
					i++;
				}
				if (count == 0) city.name = buf;
				else if (count == 1) city.x = stof(buf);
				else if (count == 2) city.y = stof(buf);
				else if (count == 3) city.faction_owner = buf;
				else if (count == 4) city.peasants = stoi(buf);
				else if (count == 5) city.workers = stoi(buf);
				else if (count == 6) city.nobles = stoi(buf);
				else if (count == 7) city.priests = stoi(buf);
				else if (count == 8) city.birth_rate = stoi(buf);
				else if (count == 9) city.death_rate = stoi(buf);
				else if (count == 10) city.food = stoi(buf);
				else if (count == 11) city.type = buf;
				count++;
				cout << buf << " ";
			}
		cout << endl;
		city.population = city.peasants + city.workers + city.nobles + city.priests;
		city.growth = city.birth_rate - city.death_rate;
		citiesList.push_back(city);
		}
	}
	file_cities.close();
}
