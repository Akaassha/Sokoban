#include "Player.h"
#include "Game.h"
#include "map.h"
#include "Tile.h"

void Player::move(Direction direction, int distance)
{
	if (!canMove(direction, distance)) { return; };

	Map* map = Game::GetGame().map;

	switch (direction)
	{
	case Direction::up:
		map->swapTails(pos_x, pos_y, pos_x, pos_y - distance);
		pos_y = pos_y - distance;
		break;

	case Direction::down:
		map->swapTails(pos_x, pos_y, pos_x, pos_y + distance);
		pos_y = pos_y + distance;
		break;

	case Direction::left:
		map->swapTails(pos_x - distance, pos_y, pos_x, pos_y);
		pos_x = pos_x - distance;
		break;

	case Direction::right:
		map->swapTails(pos_x + distance, pos_y, pos_x, pos_y);
		pos_x = pos_x + distance;
		break;
	}
}

bool Player::canMove(Direction direction, int distance)
{
	Map* map = Game::GetGame().map;
	Tile tile;

	//directions(direction, pos_x, pos_y, distance, map->GetTile);

	switch (direction)
	{
	case Direction::up:
		tile = map->GetTile(pos_x, pos_y - distance);
		break;
	case Direction::down:
		tile = map->GetTile(pos_x, pos_y + distance);
		break;
	case Direction::left:
		tile = map->GetTile(pos_x - distance, pos_y );
		break;
	case Direction::right:
		tile = map->GetTile(pos_x + distance, pos_y );
		break;
	}

	if (tile.type == Tile::tileType::wall)
	{
		return false;
	}

	return true;
}

