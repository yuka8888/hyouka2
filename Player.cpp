#include "Player.h"
#include "Struct.h"
#include <Novice.h>

Player::Player() {
	player_.position = { 100, 500 };
	player_.radius = 50;
	player_.speed = 6;
	isAlive_ = true;

	bullet_ = new Bullet;
}

Player::~Player() {
	delete bullet_;
}

int Player::Update(char* keys, char* preKeys) {
	//移動
	if (keys[DIK_W]) {
		player_.position.y -= player_.speed;
	}
	else if (keys[DIK_S]) {
		player_.position.y += player_.speed;
	}
	else if (keys[DIK_A]) {
		player_.position.x -= player_.speed;
	}
	else if (keys[DIK_D]) {
		player_.position.x += player_.speed;
	}

	if (player_.position.x < 0 + player_.radius) {
		player_.position.x = 0 + player_.radius;

	}
	else if (player_.position.x > 1280 - player_.radius) {
		player_.position.x = 1280 - player_.radius;
	}
	else if (player_.position.y < 0 + player_.radius) {
		player_.position.y = 0 + player_.radius;

	}
	else if (player_.position.y > 720 - player_.radius) {
		player_.position.y = 720 - player_.radius;
	}


	//弾の発射
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bullet_->GetIsShot() == false) {
		bullet_->SetBullet(player_.position);
		bullet_->SetIsShot(true);
	}

	bullet_->Update();

	return 0;
}

void Player::Draw() {
	bullet_->Draw();
	if (isAlive_ == true) {
		Novice::DrawEllipse(player_.position.x, player_.position.y, player_.radius, player_.radius, 0.0f, WHITE, kFillModeSolid);
	}
}
