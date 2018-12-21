#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "stdafx.h"
#include "dragon.h"
#include "fire.h"
#include "infiniteLevel.h"

infiniteLevel infiniteLevel::il = infiniteLevel();
int main()
{
	Context context;
	infiniteLevel il = infiniteLevel::instance();
	RenderWindow window(VideoMode(il.getWidth(), il.getHeight()), "Fire them all!");

	dragon player;
	std::vector<fire> fireball;
	std::vector<bird> enemies;

	srand(time(NULL));

restart:
	while (window.isOpen())
	{
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
					case Keyboard::Escape: window.close(); goto theend; break;
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
					window.close();
					goto theend;
				}

			}

			window.clear();
			il.drawBG(window);
			window.draw(il.score());

			if (fireball.size())
			{
				for (int i = 0; i < fireball.size(); i++) {
					window.draw(fireball[i].shoot(1.f));
					if (fireball[i].getX() >= 1024) fireball.erase(fireball.begin() + i);
				}
			}

			il.genLvl(enemies);

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
						il.count -= 10;
						if (il.count == -10) goto endgame;
					}
				}

			}

			if (fireball.size() && enemies.size()) {
				for (int i = 0; i < fireball.size(); i++) {
					for (int j = 0; j < enemies.size(); j++) {
						if (enemies[j].getRect().intersects(fireball[i].getRect())) {
							enemies.erase(enemies.begin() + j);
							fireball.erase(fireball.begin() + i);
							il.count += 10;
							break;
						}
					}

				}
			}

			window.draw(player.anim());
			window.display();
	}

endgame:
	il.printText(window);
	window.display();
	Event event;
	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
				window.close();
				goto theend;
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::W ||
					event.key.code == Keyboard::S ||
					event.key.code == Keyboard::Up ||
					event.key.code == Keyboard::Down) break;
				enemies.clear();
				fireball.clear();
				il.count = 0;
				goto restart;
			}
		}
	}
theend:
	return 0;
}

