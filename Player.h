#pragma once
#include"Struct.h"
#include "Bullet.h"

class Player {
public:
	//メンバ変数
	Transform pos_;
	float radius_;
	float speed_;
	int isAlive_;
	Bullet *bullet_;

	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	void Update(char *keys,int &playerHp);

	void Draw();
};

