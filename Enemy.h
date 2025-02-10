#pragma once
#include "Struct.h"
#include "Novice.h"
#include "Player.h"

class Enemy {
public:
	//コンストラクタ
	Enemy(Player *player, Transform pos_, float speed);

	//デストラクタ
	~Enemy();

	virtual void Update(int gameTimer, int &playerHp,int &score,Transform pos_);
	virtual void Draw();
	
	//アクセッサ
	Transform GetPos() { return pos_; }
	float GetRadius() { return radius_; }
	float GetSpeed() { return speed_; }

	void SetPos(float x,float y);
	void Setspeed(float speed);

public:
	//メンバ変数
	Player *playerBullet_;
	int isAlive_;
	int respornTimer_;
	int isDamaged_;

private:
	//メンバ変数
	Transform pos_;
	float speed_;
	float radius_;
};

