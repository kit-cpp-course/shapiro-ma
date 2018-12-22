#include "infiniteLevel.h"

infiniteLevel::infiniteLevel() : gameController(1024, 600, "src/img/part1.png", "src/font/12030.ttf") {
	sp[0].setTexture(background);
	sp[1].setTexture(background);
};

void infiniteLevel::drawBG(RenderWindow & window) {
	sp[0].setPosition(x + width, 0);
	sp[1].setPosition(x, 0);
	x -= 0.1f;
	window.draw(sp[0]);
	window.draw(sp[1]);
	if ((int)x == -width) {
		x = 0;
	}
}

void infiniteLevel::genLvl(std::vector<bird> & enemies) {
	if (cl.getElapsedTime().asSeconds() > 1.5f) {
		bird b(1300.f, rand() % 344);
		enemies.push_back(b);
		cl.restart();
	}
}

Text infiniteLevel::score(){
	return setText("Score: " + std::to_string(count), 24);
}

void infiniteLevel::printText(RenderWindow & window) {
	window.draw(setText("Game over", 100, { 250,230 }));
	window.draw(setText("Press any key to restart...", 40, { 250,340 }));
	window.draw(setText("Press escape to exit...", 40, { 250,385 }));
}