#include "Function.h"

int HitCheck(Transform enemy1, Transform enemy2) {
	int x = enemy1.position.x - enemy2.position.x;
	int y = enemy1.position.y - enemy2.position.y;

	if ((enemy1.radius + enemy2.radius) * (enemy1.radius + enemy2.radius) >= x * x + y * y) {
		return 1;
	}
	else {
		return 0;
	}
}
