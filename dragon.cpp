#include "dragon.h"

dragon::dragon() : flyingObject(-100.f, 172.f, "src/img/dspr.png", { -100.f, 172.f + 128 - 50,256,100 }) {}

void dragon::move(float speed) {
	if (position.y >= 600 - 128) position.y = -127.f;
	if (position.y <= -128) position.y = 600 - 128;
	bound.top = position.y + 128 - 50;
	bound.top += speed;
	position.y += speed;
}
