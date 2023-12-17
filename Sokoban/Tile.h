#pragma once

#include <iostream>

class Tile
{

public:
	enum class tileType
	{
		wall,
		floor,
		goal,
		barre,
		player
	};

	Tile() : type{ tileType::wall } {};
	Tile(tileType type) : type{ type } {};
	Tile(char c);

	tileType type;

	friend std::ostream& operator<<(std::ostream& os, const Tile tile);
};

