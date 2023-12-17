#include "Tile.h"

Tile::Tile(char c)
{
	switch (c)
	{
	case '#':
		type = tileType::wall;
		break;
	case '%':
		type = tileType::player;
		break;

	default:
		type = tileType::wall;
		break;
	}
}

std::ostream& operator<<(std::ostream& os, const Tile tile)
{
	switch (tile.type)
	{
	case Tile::tileType::wall:
		os << '#';
		break;
	case Tile::tileType::player:
		os << '%';
		break;
	}

	return os;
}