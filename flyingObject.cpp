#include "flyingObject.h"

flyingObject::flyingObject(float x, float y, std::string texturePath, Rect<float> bound) : position(x, y), bound(bound), rect(0, 0, 256, 256) {
	texture.loadFromFile(texturePath);
}


Sprite flyingObject::anim() {
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

Rect<float> flyingObject::getRect() const {
	return bound;
}

Vector2<float> flyingObject::getXY() const {
	return position;
}