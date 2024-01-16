#pragma once
#include "Struct.h"

class Enemy
{
public:
	Enemy();

	~Enemy();

	void Update();

	void Draw();

	Transform GetEnemy() { return enemy_; }

	int GetRemain() { return remain_; }

	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }

	void SetRemain(int remain) { remain_ = remain; }

	bool GetIsAlive() { return isAlive_; }


private:
	Transform enemy_;
	bool isAlive_;
	int remain_;
	int respawnTimer_;
};

