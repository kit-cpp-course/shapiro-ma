#pragma once
#include "gameController.h"

class infiniteLevel : public gameController {

	/*
	* Переменная, необходимая для отрисовки движения фона
	*/
	float x = 0;

	/*
	* Спрайты, необходимые для отрисовки движения фона
	*/
	Sprite sp[2];

public:

	/*
	* Основной конструктор класса
	*/
	infiniteLevel();

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