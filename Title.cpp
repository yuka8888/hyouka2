#include <Novice.h>
#include "Title.h"
#include "Function.h"

Title::Title() {
	isNextScene_ = false;
	nextScene_ = PLAY;
}

void Title::Update(char* keys) {
	if (keys[DIK_RETURN]) {
		isNextScene_ = true;
		nextScene_ = PLAY;
	}
}

void Title::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
}

void Title::Initialization() {
	isNextScene_ = false;
}
