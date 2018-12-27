#pragma once
#include "gameController.h"

class infiniteLevel : public gameController{
	friend class gameController;

	/*
	* Переменная, необходимая для отрисовки движения фона
	*/
	float x = 0;

	/*
	* Спрайты, необходимые для отрисовки движения фона
	*/
	Sprite sp[2];

	/*
	* Основной конструктор класса
	*/
	infiniteLevel();
	
public:

	/*
	* Отрисовка движущегося фона
	*/
	void drawBG(RenderWindow & window);

	/*
	* Генерация уровня
	*/
	void genLvl(std::vector<bird> & enemies);

	/*
	* Возвращает надпись, содержащую информацию о количестве очков
	*/
	Text score();

	/*
	* Отрисовывает текст
	*/
	void printText(RenderWindow & window);
};

gameController * gameController::createController() {
	if (!gc) {
		gc = new infiniteLevel();
		return gc;
	}
	else return gc;
}