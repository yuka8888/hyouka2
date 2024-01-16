#include <Novice.h>
#include "Play.h"
#include "Player.h"
#include "Enemy.h"
#include "Function.h"

Play::Play() {
	player_ = new Player;
	enemy_ = new Enemy;
	isNextScene_ = false;
	nextScene_ = TITLE;
}

void Play::Update(char* keys, char* preKeys) {

	player_->Update(keys, preKeys);
	enemy_->Update();

	//敵とプレイヤーの弾の当たり判定

	if (HitCheck(enemy_->GetEnemy(), player_->bullet_->GetBullet()) && enemy_->GetIsAlive() == true) {
		enemy_->SetRemain(enemy_->GetRemain() - 1);
		enemy_->SetIsAlive(false);
	}

	//プレイヤーと敵の当たり判定

	if (HitCheck(player_->GetPlayer(), enemy_->GetEnemy())) {
		player_->SetIsAlive(false);
	}

	//敵かプレイヤーが死んだらシーン切り替え

	if (player_->GetIsAlive() == false) {
		isNextScene_ = true;
		nextScene_ = OVER;
	}
	else if (enemy_->GetRemain() <= 0) {
		isNextScene_ = true;
		nextScene_ = CLEAR;
	}

}

void Play::Draw() {
	player_->Draw();
	enemy_->Draw();
}

void Play::Initialization() {
	delete player_;
	delete enemy_;

	player_ = new Player;
	enemy_ = new Enemy;
	isNextScene_ = false;
	nextScene_ = PLAY;
}