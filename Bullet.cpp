#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet() {
	radius_ = 10;
	speed_ = 7;
	for (int i = 0; i < bulletNum_; i++) {
		pos_[i] = { 0.0f,0.0f };
		isShot_[i] = false;
	}
}

Bullet::~Bullet() {
}

void Bullet::Update() {
	for (int i = 0; i < bulletNum_; i++) {
		if (isShot_) {
			pos_[i].y -= speed_;
		}

		if (pos_[i].y <= 0) {
			isShot_[i] = false;
		}
	}
}

void Bullet::Draw() {
	int whiteGH = Novice::LoadTexture("white1x1.png");
	for (int i = 0; i < bulletNum_; i++) {
		if (isShot_[i]) {
			Novice::DrawSprite(int(pos_[i].x), int(pos_[i].y), whiteGH, radius_, radius_, 0.0f, 0xFF00FFFF);
		}
	}
}
