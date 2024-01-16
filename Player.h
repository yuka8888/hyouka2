#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player
{
public:
	Player();

	~Player();

	int Update(char* keys, char* preKeys);

	void Draw();

	Bullet* bullet_;

	Transform GetPlayer() { return player_; }

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }

	bool GetIsAlive() { return isAlive_; }


private:
	Transform player_;
	bool isAlive_;
};

