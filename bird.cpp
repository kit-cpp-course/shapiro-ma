#include "bird.h"

bird::bird(float x, float y) : position(x,y), rect(0, 0, 256, 256) {
	texture.loadFromFile("src/img/brd.png");
	bound.left = position.x + 15;
	bound.top = position.y + 128 - 25;
	bound.width = 50;
	bound.height = 50;
}

void bird::move(float speed) {
	bound.left -= speed;
	position.x -= speed;
}

Sprite bird::anim() {
	Sprite sp(texture, rect);
	sp.setPosition(position.x, position.y);

	if (frametime.getElapsedTime().asSeconds() > 0.2f) {
		if (rect.left == 0) rect.left = 256;
		else rect.left -= 256;

		sp.setTextureRect(rect);		
		frametime.restart();
	}
	return sp;
}

Rect<float> bird::getRect() const{
	return bound;
}

Vector2<float> bird::getXY() const{
	return position;
}