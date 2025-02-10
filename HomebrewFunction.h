#pragma once
class HomebrewFunction {
public:
	/*
	ax 参照したい矩形1の左上座標X
	ay 参照したい矩形1の左上座標Y
	aWidth_x 参照したい矩形1の横幅
	aWidth_y 参照したい矩形1の縦幅
	ax 参照したい矩形2の左上座標X
	ay 参照したい矩形2の左上座標Y
	bWidth_x 参照したい矩形2の横幅
	bWidth_y 参照したい矩形2の縦幅
	*/
	static int IsHitDetection(float ax, float ay, float aWidthX, float aWidthY, float bx, float by, float bWidthX, float bWidthY);
};

