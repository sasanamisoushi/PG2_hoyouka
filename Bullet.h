#pragma once
#include "Struct.h"
class Bullet {
public:

	Bullet();
	~Bullet();
	void Update();
	void Draw();

	static const int bulletNum_ = 10;
	Transform pos_[bulletNum_];
	float radius_;
	float speed_;
	int isShot_[bulletNum_];
};

