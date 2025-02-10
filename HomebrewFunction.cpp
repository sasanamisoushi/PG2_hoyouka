#include "HomebrewFunction.h"

//四角の当たり判定
int HomebrewFunction::IsHitDetection(float ax, float ay, float aWidthX, float aWidthY, float bx, float by, float bWidthX, float bWidthY) {
	float ax1 = ax;
	float ay1 = ay;
	float ax2 = ax + aWidthX;
	float ay2 = ay + aWidthY;
	float bx1 = bx;
	float by1 = by;
	float bx2 = bx + bWidthX;
	float by2 = by + bWidthY;
	if (bx1 < ax2 && ax1 < bx2) {
		if (by1 < ay2 && ay1 < by2) {
			return true;
		}
	}
	return false;
}
