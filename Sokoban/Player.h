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

public:
	Player(int x, int y) : pos_x{ x }, pos_y{ y } {};

	void move(Direction direction, int distance);

private:
	bool canMove(Direction direction, int distance);
	void getCoordsOfNextTiles(Direction direction, int distance, int& x, int& y, int& next_x, int& next_y);
};

