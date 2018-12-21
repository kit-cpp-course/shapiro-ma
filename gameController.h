#pragma once
#include "stdafx.h"
#include "bird.h"

class gameController {
protected:
	/*
	* Ширина окна
	*/
	short width;

	/*
	* Высота окна
	*/
	short height;

	/*
	* Текстура фона
	*/
	Texture background;


	/*
	* Основной шрифт
	*/
	Font font;

	/*
	* Отсчёт времени с момента начала игры
	*/
	Clock cl;

	/*
	* Настройка надписей
	*/
	Text setText(std::string content, short size, Vector2<short> position = { 0,0 }, Color color = Color::Black);
public:

	/*
	* Основной конструктор класса, принимающий ширину, высоту окна, путь к изображению фона и шрифту
	*/
	gameController(short width, short height, std::string backgroundPath, std::string fontPath);

	/*
	* Отрисовка фона
	*/
	virtual void drawBG(RenderWindow & window) = 0;

	/*
	* Генерация уровня, принимает список врагов
	*/
	virtual void genLvl(std::vector<bird> & enemies) = 0;

	/*
	* Возвращает надпись, содержащую информацию о количестве очков
	*/
	virtual Text score() = 0;

	/*
	* Отрисовывает текст
	*/
	virtual void printText(RenderWindow & window) = 0;

	/*
	* Возвращает ширину окна
	*/
	short getWidth() const;

	/*
	* Возвращает высоту окна
	*/
	short getHeight() const;
};