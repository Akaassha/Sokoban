#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include "map.h"
#include "Player.h"

using namespace std;

bool checkWin()
{
	auto goals = Game::GetGame().goals;
	auto map = Game::GetGame().map;
	int goalsAmount = goals.size();
	int checked = 0;

	for (auto goal : goals)
	{
		if (map->GetTile(goal.first, goal.second).type == Tile::tileType::barrel)
		{
			checked++;
		}
	}

	if (checked == goalsAmount)
		return false;
	else
		return true;
		
}

int main()
{
	Map map("TestMap.txt");
	Player* player = Game::GetGame().player;

	char input;
	while (checkWin())
	{
		map.draw();

		input = _getch();
		switch (input)
		{
		case 'w':
			player->move(Direction::up, 1);
			break;
		case 's':
			player->move(Direction::down, 1);
			break;	
		case 'a':
			player->move(Direction::left, 1);
			break;	
		case 'd':
			player->move(Direction::right, 1);
			break;

		default:
			break;
		}
	}

	map.draw();
	cout << endl;
	cout << "you have won!!";
}