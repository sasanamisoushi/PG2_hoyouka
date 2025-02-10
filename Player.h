#pragma once
#include"Struct.h"
#include "Bullet.h"

class Player {
public:
	//ゲッター
    float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	float GetRadius() { return radius_; }
	float GetSpeed() { return speed_; }
	int GetIsAlive() { return isAlive_; }
	int GetAdditionHp() { return additionHp_; }

	//セッター
	float  SetPosX(float x) { x = pos_.x; };
	float SetPosY(float y) { y = pos_.y; };
	float Setspeed(float speed) { speed = speed_; };
	float SetRadius(float radius) { radius = radius_; };

	//メンバ変数
	Bullet  *bullet_;

	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	void Update(char *keys,int &playerHp,int score);

	void Draw();

private:
	//メンバ変数
	Transform pos_;
	float radius_;
	float speed_;
	int isAlive_;
	int additionHp_;

};

