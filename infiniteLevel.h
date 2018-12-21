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

	/*
	* Основной конструктор класса
	*/
	infiniteLevel();

	/*
	* Экземпляр класса
	*/
	static infiniteLevel il;
public:
	/*
	* Счётчик очков
	*/
	int count = 0;

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

	/*
	* Возвращает ссылку на экземпляр класса
	*/
	static infiniteLevel & instance();
};