#pragma once
#include <vector>

class Game
{
public:
	class Map* map;
	class Player* player;
	std::vector<std::pair<int, int>> goals;

public:
	static Game& GetGame()
	{
		static Game instance;
		return instance;
	}

private:

	Game() : map{ nullptr }, player{ nullptr } {};
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
};