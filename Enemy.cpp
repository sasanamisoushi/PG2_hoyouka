#include "Enemy.h"
#include <stdlib.h>
#include "HomebrewFunction.h"




Enemy::Enemy(Player *player, Transform pos, float speed) {
	pos_.x = pos.x;
	pos_.y = pos.y;
	radius_ = 32.0f;
	speed_ = speed;
	isAlive_ = false;
	playerBullet_ = player;
	respornTimer_ = 0;
	isDamaged_ = false;
}

void Enemy::SetPos(float x, float y) {
	pos_.x = x;
	pos_.y = y;
}

void Enemy::Setspeed(float speed) {
	speed_ = speed;
}


Enemy::~Enemy() {

}

void Enemy::Update(int gameTimer, int &playerHp, int &score, Transform pos) {
	//敵が生きてる時だけ
	if (isAlive_) {
		pos_.y += speed_;
	}

	// 画面外に出たらプレイヤーのHPを減らす
	if (pos_.y + radius_ >= 600.0f) {
		if (!isDamaged_) {
			playerHp -= 1;
			score -= 100;
			isDamaged_ = true;
		}
		isAlive_ = false;
	}

	//ゲームタイマーが起動してるときだけ敵が生き返ってX座標はランダムで出す
	if (gameTimer < 2000) {
		if (respornTimer_ <= 0) {
			if (!isAlive_) {
				isAlive_ = true;
				isDamaged_ = false;
				pos_.y = pos.y;
				pos_.x = pos.x;
			}
			respornTimer_ = 100;
		} else {
			respornTimer_--;
		}
	}

	//敵が画面外にリスポーンしたときfalse
	if (pos_.x <= 0 || pos.x > 460) {
		isAlive_ = false;
	}

	//弾との当たり判定
	for (int i = 0; i < playerBullet_->bullet_->bulletNum_; i++) {
		if (isAlive_) {
			if (HomebrewFunction::IsHitDetection(
				playerBullet_->bullet_->pos_[i].x, playerBullet_->bullet_->pos_[i].y,
				playerBullet_->bullet_->radius_, playerBullet_->bullet_->radius_,
				pos_.x, pos_.y, radius_, radius_)) {
				score += 100;
				isAlive_ = false;
				playerBullet_->bullet_->isShot_[i] = false;
			}
		}
	}

	//自機との当たり判定
	if (isAlive_) {
		if (HomebrewFunction::IsHitDetection(
			playerBullet_->GetPosX() ,playerBullet_->GetPosY(),
			playerBullet_->GetRadius(), playerBullet_->GetRadius(),
			pos_.x, pos_.y, radius_, radius_)) {
			score += 100;
			isAlive_ = false;
			if (!isDamaged_) {
				playerHp -= 1;
				isDamaged_ = true;
			}
		}
	}


}

void Enemy::Draw() {
	//描画
	int whiteGH = Novice::LoadTexture("white1x1.png");
	if (isAlive_) {
		Novice::DrawSprite(int(pos_.x), int(pos_.y), whiteGH, 32.0f, 32.0f, 0.0f, 0xFFFFFFFF);
	}
}
