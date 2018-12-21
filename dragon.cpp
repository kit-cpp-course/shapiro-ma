#include "dragon.h"

dragon::dragon() : bird(-100.f, 172.f) {
	texture.loadFromFile("src/img/dspr.png");
	bound.left = position.x;
	bound.top = position.y + 128 - 50;
	bound.width = 256;
	bound.height = 100;
}

void dragon::move(float speed) {
	if (position.y >= 600 - 128) position.y = -127.f;
	if (position.y <= -128) position.y = 600 - 128;
	bound.top = position.y + 128 - 50;
	bound.top += speed;
	position.y += speed;
}
