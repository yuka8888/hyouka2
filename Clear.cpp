#include <Novice.h>
#include "Clear.h"
#include "Function.h"

Clear::Clear() {
	isNextScene_ = false;
	nextScene_ = TITLE;
}

void Clear::Update(char* keys) {
	if (keys[DIK_SPACE]) {
		isNextScene_ = true;
		nextScene_ = TITLE;
	}
}

void Clear::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
}

void Clear::Initialization() {
	isNextScene_ = false;
}
