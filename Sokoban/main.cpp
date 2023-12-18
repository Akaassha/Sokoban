#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include "map.h"
#include "Player.h"

using namespace std;

int main()
{
	Map map("TestMap.txt");
	Player* player = Game::GetGame().player;

	char input;
	while (true)
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
}