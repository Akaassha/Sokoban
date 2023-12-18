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
	case '_':
		type = tileType::floor;
		break;
	case 'O':
		type = tileType::barrel;
		break;
	case 'x':
		type = tileType::goal;
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
	case Tile::tileType::floor:
		os << ' ';
		break;
	case Tile::tileType::barrel:
		os << 'O';
		break;
	case Tile::tileType::goal:
		os << 'x';
		break;
	}

	return os;
}