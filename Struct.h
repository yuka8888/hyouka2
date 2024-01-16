#pragma once

struct Vector2 final {
	int x;
	int y;
};

struct Transform final {
	Vector2 position;
	int radius;
	int speed;
};

enum Scene {
	TITLE,
	PLAY,
	CLEAR,
	OVER
};
