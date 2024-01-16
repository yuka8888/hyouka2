#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	bullet_.position = { -100,-100 };
	bullet_.radius = 10;
	bullet_.speed = 8;
	isShot_ = false;

}

void Bullet::Update() {

	if (isShot_ == true) {
		bullet_.position.y -= bullet_.speed;
	}

	if (bullet_.position.y < 0) {
		isShot_ = false;
	}

}

void Bullet::Draw() {
	if (isShot_ == true) {
		Novice::DrawEllipse(bullet_.position.x, bullet_.position.y, bullet_.radius, bullet_.radius, 0.0f, BLUE, kFillModeSolid);
	}
}

