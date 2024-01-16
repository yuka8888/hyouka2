#pragma once
#include "Play.h"
#include "Player.h"
#include "Enemy.h"
#include "Function.h"

class Play
{
public:
	Play();

	void Update(char* keys, char* preKeys);

	void Draw();

	void Initialization();

	bool GetIsNextScene() { return isNextScene_; }

	Scene GetNextScene() { return nextScene_; }

private:
	Player* player_;

	Enemy* enemy_;

	bool isNextScene_;

	Scene nextScene_;
};
