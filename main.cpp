#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "stdafx.h"
#include "bird.h"
#include "dragon.h"
#include "fire.h"
#include "gameController.h"

gameController * gameController::gc = NULL;
int main()
{
	Context context;
	gameController * gc = gameController::createController();

	RenderWindow window(VideoMode(gc->getWidth(), gc->getHeight()), "Fire them all!");

	dragon player;
	std::vector<fire> fireball;
	std::vector<bird> enemies;

	srand(time(NULL));

restart:
	while (window.isOpen())
	{
		if (!gc->keys(window, player, fireball)) goto theend;

		window.clear();
		gc->drawBG(window);
		window.draw(gc->score());

		if (fireball.size())
		{
			for (int i = 0; i < fireball.size(); i++) {
				window.draw(fireball[i].shoot(1.f));
				if (fireball[i].getX() >= gc->getWidth()) fireball.erase(fireball.begin() + i);
			}
		}

		gc->genLvl(enemies);

		if (enemies.size())
		{
			for (int i = 0; i < enemies.size(); i++) {
				window.draw(enemies[i].anim());
				enemies[i].move(0.4f);
				if (enemies[i].getRect().intersects(player.getRect())) {
					goto endgame;
				}
				if (enemies[i].getXY().x <= -128) {
					enemies.erase(enemies.begin() + i);
					gc->count -= 10;
					if (gc->count == -10) goto endgame;
				}
			}

		}

		if (fireball.size() && enemies.size()) {
			for (int i = 0; i < fireball.size(); i++) {
				for (int j = 0; j < enemies.size(); j++) {
					if (enemies[j].getRect().intersects(fireball[i].getRect())) {
						enemies.erase(enemies.begin() + j);
						fireball.erase(fireball.begin() + i);
						gc->count += 10;
						break;
					}
				}

			}
		}

		window.draw(player.anim());
		window.display();
	}

endgame:
	gc->printText(window);
	window.display();
	while (true) {

		if (gc->keys(window) == windowClosed) {
			goto theend;
		}
		if (gc->keys(window) == keyPressed) {
			enemies.clear();
			fireball.clear();
			gc->count = 0;
			goto restart;
		}
	}
theend:
	window.close();
	return 0;
}

