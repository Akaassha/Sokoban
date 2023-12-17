#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"

template<class T>
class Map
{
	Tile** Tiles;
	int height = 0;
	int width = 0;

public:
	Map(std::string filename);
	Map() = delete;

	void draw();

private:
	std::vector<std::string> read_map(std::string filename);
};

template<class T>
Map<T>::Map(std::string filename)
{
	std::vector<std::string> map_data = read_map(filename);

	width = stoi(map_data[0]);
	height = stoi(map_data[1]);

	Tiles = new Tile* [width * height];

	for (int y = 0; y != height; y++)
	{
		Tiles[y] = new Tile [width];
		for (int x = 0; x != width; x++)
		{
			Tiles[y][x] = Tile(map_data[y+2][x]);
		}
	}
};

template<class T>
void Map<T>::draw()
{
	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			std::cout << Tiles[y][x];
		}

		std::cout << std::endl;
	}
};

template<class T>
std::vector<std::string> Map<T>::read_map(std::string filename)
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