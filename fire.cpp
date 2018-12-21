#include "fire.h"

fire::fire(const Vector2<float> position) : position(position.x + 256, position.y + 100), bound(position.x + 256, position.y + 100, 50, 50) {
	texture.loadFromFile("src/img/fb.png");
}

Sprite fire::shoot(float speed) {
	Sprite sp(texture);
	sp.setPosition(position.x, position.y);
	bound.left += speed;
	position.x += speed;
	return sp;
}

Rect<float> fire::getRect() const{
	return bound;
}

float fire::getX() const {
	return position.x;
}
