#pragma once
#include"Struct.h"

class Clear
{
public:
	Clear();

	void Update(char* keys);

	void Draw();

	void Initialization();

	bool GetIsNextScene() { return isNextScene_; }

	Scene GetNextScene() { return nextScene_; }

private:
	bool isNextScene_;

	Scene nextScene_;
};
