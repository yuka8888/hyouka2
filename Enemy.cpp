#include "Enemy.h"
#include "Player.h"
#include "Novice.h"

Enemy::Enemy() {
	enemy_.position.x = 100;
	enemy_.position.y = 100;
	remain_ = 3;
	enemy_.radius = 30;
	enemy_.speed = 10;
	isAlive_ = true;
	respawnTimer_ = 30;
}

Enemy::~Enemy() {}

void Enemy::Update() {
	// 移動 
	enemy_.position.x += enemy_.speed;

	if (enemy_.position.x >= 1280 - enemy_.radius) {
		enemy_.position.x = 1280 - enemy_.radius;
		enemy_.speed *= -1;
	}
	else if (enemy_.position.x <= enemy_.radius) {
		enemy_.position.x = enemy_.radius;
		enemy_.speed *= -1;
	}

	if (isAlive_ == false) {
		respawnTimer_--;
		if (respawnTimer_ <= 0) {
			isAlive_ = true;
			respawnTimer_ = 30;
		}
	}

}

void Enemy::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(enemy_.position.x, enemy_.position.y, enemy_.radius, enemy_.radius, 0.0f, RED, kFillModeSolid);
	}
}