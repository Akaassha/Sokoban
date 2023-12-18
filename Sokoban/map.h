#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Player.h"
#include "Game.h"

class Map
{
	Tile** Tiles;
	Player* player;
	int height = 0;
	int width = 0;

public:
	Map(std::string filename);
	Map() = delete;

	void draw();
	void swapTails(int Tile1_x, int Tile1_y, int Tile2_x, int Tile2_y);

	const Tile& GetTile(int x, int y);
	void SetTile(int x, int y, Tile::tileType type);

private:
	std::vector<std::string> read_map(std::string filename);
};
