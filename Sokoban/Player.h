#pragma once

enum class Direction
{
	left,
	right,
	up,
	down
};

class Player
{
	int pos_x;
	int pos_y;
	//class Map* current_map;

public:
	Player(int x, int y) : pos_x{ x }, pos_y{ y } {};
	//
	void move(Direction direction, int distance);

private:
	bool canMove(Direction direction, int distance);
};

