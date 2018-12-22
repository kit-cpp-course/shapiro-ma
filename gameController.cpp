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

bool gameController::keys(RenderWindow & window, dragon & player, std::vector<fire> & fireball) {
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case Event::KeyPressed:
			switch (event.key.code) {
			case Keyboard::W:
			case Keyboard::Up: player.move(-10); break;
			case Keyboard::S:
			case Keyboard::Down: player.move(10); break;
			case Keyboard::Escape: return false;
			case Keyboard::Space:
			case Keyboard::Enter: fire ball(player.getXY()); fireball.push_back(ball); break;
			}
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				fire ball(player.getXY()); fireball.push_back(ball);
			}
			break;
		case Event::Closed:
			return false;
		}

	}

	return true;
}

short gameController::keys(RenderWindow & window) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
			return windowClosed;
		}
		else if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::W ||
				event.key.code == Keyboard::S ||
				event.key.code == Keyboard::Up ||
				event.key.code == Keyboard::Down) break;
			return keyPressed;
		}
	}
}

short gameController::getWidth() const {
	return width;
}

short gameController::getHeight() const {
	return height;
}