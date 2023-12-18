#include "map.h"
#include <iostream>
#include <fstream>
#include <vector>


Map::Map(std::string filename)
{
	std::vector<std::string> map_data = read_map(filename);

	width = stoi(map_data[0]);
	height = stoi(map_data[1]);
	Game& game = Game::GetGame();

	Tiles = new Tile * [width * height];

	for (int y = 0; y != height; y++)
	{
		Tiles[y] = new Tile[width];
		for (int x = 0; x != width; x++)
		{
			Tiles[y][x] = Tile(map_data[y + 2][x]);
			if (Tiles[y][x].type == Tile::tileType::player)
			{
				player = new Player(x, y);
				
				game.map = this;
				game.player = player;
			}

			if (Tiles[y][x].type == Tile::tileType::goal)
			{
				game.goals.push_back(std::pair<int, int>(x, y));
			}
		}
	}
};

void Map::draw()
{
	system("cls");

	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			std::cout << Tiles[y][x];
		}

		std::cout << std::endl;
	}
};

std::vector<std::string> Map::read_map(std::string filename)
{
	std::ifstream file_handle(filename);

	if (!file_handle.good())
	{
		throw std::runtime_error("Cannot open file.");
	}

	std::vector<std::string> lines;
	std::string line;
	while (file_handle >> line)
	{
		if (line.size() <= 0)
		{
			file_handle.close();
			throw std::runtime_error("File structure is not correct.");
		}
		lines.push_back(line);
	}

	file_handle.close();

	return lines;
};

const Tile& Map::GetTile(int x, int y)
{
	return Tiles[y][x];
}

void Map::swapTails(int Tile1_x, int Tile1_y, int Tile2_x, int Tile2_y)
{
	std::swap(Tiles[Tile1_y][Tile1_x], Tiles[Tile2_y][Tile2_x]);
}

void Map::SetTile(int x, int y, Tile::tileType type)
{
	Tiles[y][x].type = type;
}