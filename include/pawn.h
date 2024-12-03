#pragma once
#include <raylib.h>

class Pawn {

public:
	Vector2 position;
	int speed;
	int radius;
	Rectangle area;

	virtual void draw() = 0;
	virtual void update() = 0;
};