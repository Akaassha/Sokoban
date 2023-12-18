#pragma once

class Game
{
public:
	class Map* map;
	class Player* player;

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

//void directions(Direction direction, int x, int y, int distance, void (*Fun)(int, int))
//{
//	switch (direction)
//	{
//	case Direction::up:
//		Fun(x, y - distance);
//		break;
//	case Direction::down:
//		Fun(x, y + distance);
//		break;
//	case Direction::left:
//		Fun(x + distance, y);
//		break;
//	case Direction::right:
//		Fun(x - distance, y);
//		break;
//	}
//}