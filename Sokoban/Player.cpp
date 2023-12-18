#include "Player.h"
#include "Game.h"
#include "map.h"
#include "Tile.h"

void Player::move(Direction direction, int distance)
{
	if (!canMove(direction, distance)) { return; };

	Game& game = Game::GetGame();
	Map* map = game.map;

	int x = pos_x;
	int y = pos_y;
	int next_x = x;
	int next_y = y;

	getCoordsOfNextTiles(direction, distance, x, y, next_x, next_y);

	switch (map->GetTile(x, y).type)
	{
		case Tile::tileType::floor:
		{
			map->swapTails(x, y, pos_x, pos_y);
			break;
		}

		case Tile::tileType::barrel:
		{
			if (map->GetTile(next_x, next_y).type == Tile::tileType::goal)
			{
				map->SetTile(next_x, next_y, Tile::tileType::barrel);
				map->SetTile(x, y, Tile::tileType::player);
				map->SetTile(pos_x, pos_y, Tile::tileType::floor);
			}
			else 
			{
				map->swapTails(x, y, next_x, next_y);
				map->swapTails(pos_x, pos_y, x, y);
			}
			
			break;
		}

		case Tile::tileType::goal:
		{
			map->SetTile(x, y, Tile::tileType::player);
			map->SetTile(pos_x, pos_y, Tile::tileType::floor);
			break;
		}

	}

	for (auto goal : game.goals)
	{
		if (pos_x == goal.first && pos_y == goal.second)
			map->SetTile(pos_x, pos_y, Tile::tileType::goal);
	}

	pos_x = x;
	pos_y = y;
}

bool Player::canMove(Direction direction, int distance)
{
	Map* map = Game::GetGame().map;
	Tile tile;

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

	if (tile.type == Tile::tileType::barrel)
	{
		switch (direction)
		{
		case Direction::up:
			tile = map->GetTile(pos_x, pos_y - distance -1);
			break;
		case Direction::down:
			tile = map->GetTile(pos_x, pos_y + distance+1);
			break;
		case Direction::left:
			tile = map->GetTile(pos_x - distance-1, pos_y);
			break;
		case Direction::right:
			tile = map->GetTile(pos_x + distance+1, pos_y);
			break;
		}
	}

	if (tile.type == Tile::tileType::wall || tile.type == Tile::tileType::barrel)
	{
		return false;
	}

	return true;
}

void Player::getCoordsOfNextTiles(Direction direction,int distance, int& x, int& y, int& next_x, int& next_y)
{
	switch (direction)
	{
	case Direction::up:
	{
		y -= distance;
		next_y = y - 1;
		break;
	}
	case Direction::down:
	{
		y += distance;
		next_y = y + 1;
		break;
	}
	case Direction::left:
	{
		x -= distance;
		next_x = x - 1;
		break;
	}
	case Direction::right:
	{
		x += distance;
		next_x = x + 1;
		break;
	}
	}
}