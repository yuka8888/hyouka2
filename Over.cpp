#include <Novice.h>
#include "Over.h"
#include "Function.h"

Over::Over() {
	isNextScene_ = false;
	nextScene_ = TITLE;
}

void Over::Update(char* keys) {
	if (keys[DIK_SPACE]) {
		isNextScene_ = true;
		nextScene_ = TITLE;
	}
}

void Over::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, RED, kFillModeSolid);
}

void Over::Initialization() {
	isNextScene_ = false;
}
