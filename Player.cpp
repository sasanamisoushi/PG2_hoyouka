#include "Player.h"
#include "Novice.h"
#include "Bullet.h"

Player::Player() {
	pos_.x = 100.0f;
	pos_.y = 500.0f;
	radius_ = 32.0f;
	speed_ = 5.0f;
	isAlive_ = true;
	bullet_ = new Bullet;
	additionHp_ = false;
}

Player::~Player() {
	delete bullet_;
}

void Player::Update(char *keys,int &playerHp,int score) {
	if (keys[DIK_A]) {
		if (pos_.x > 0.0f) {
			pos_.x -= speed_;
		}
	}

	if (keys[DIK_D]) {
		if (pos_.x < 1280.0f) {
			pos_.x += speed_;
		}
	}

	if (keys[DIK_SPACE]) {
		for (int i = 0; i < bullet_->bulletNum_; i++) {
			if (bullet_->isShot_[i] == false) {
				bullet_->isShot_[i] = true;
				bullet_->pos_[i].x = pos_.x + radius_ / 2.0f;
				bullet_->pos_[i].y = pos_.y + radius_ / 2.0f;
			}
		}
	}

	if (playerHp == 0) {
		isAlive_ = false;
	}

	bullet_->Update();

	if (score == 1000||score==2000||score==3000) {
		if (!additionHp_) {
			playerHp += 1;
			additionHp_ = true;
		} 
	} else {
		additionHp_ = false;
	}

}

void Player::Draw() {
	int whiteGH = Novice::LoadTexture("white1x1.png");
	bullet_->Draw();
	if (isAlive_) {
		Novice::DrawSprite(int(pos_.x), int(pos_.y), whiteGH, radius_, radius_, 0.0f, 0xFFFFFFFF);
	}
}
