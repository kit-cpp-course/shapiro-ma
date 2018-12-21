#include "gameController.h"

gameController::gameController(short width, short height, std::string bgpath, std::string fpath) : width(width), height(height) {
	if (!background.loadFromFile(bgpath)) background.create(width, height);
	if (!font.loadFromFile(fpath)) font.loadFromFile("C:/Windows/fonts/ALGER.TTF");
}

Text gameController::setText(std::string content, short size, Vector2<short> position, Color color) {
	Text text;
	text.setFont(font);
	text.setCharacterSize(size);
	text.setString(content);
	text.setPosition(position.x, position.y);
	text.setFillColor(color);
	return text;
}

short gameController::getWidth() const {
	return width;
}

short gameController::getHeight() const {
	return height;
}