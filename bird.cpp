#include "bird.h"

bird::bird(float x, float y) : flyingObject(x,y, "src/img/brd.png", {x+15, y+128-15,50,50}) {}

void bird::move(float speed) {
	bound.left -= speed;
	position.x -= speed;
}