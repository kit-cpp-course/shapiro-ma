#pragma once
#include "stdafx.h"

class bird {

	/*
	* Время длительности одного кадра анимации
	*/
	Clock frametime;

	/*
	* Прямоугольная область одного кадра анимации
	*/
	IntRect rect;

protected:
	/*
	* Текстура птицы
	*/
	Texture texture;

	/*
	* Прямоугольная область взаимодействия с объектом
	*/
	Rect<float> bound;

	/*
	* Вектор, содержащий координаты птицы
	*/
	Vector2<float> position;
public:
	/*
	* Основной конструктор, принимающий координаты начального положения птицы
	*/
	bird(float x, float y);


	/*
	* Возвращает следующий кадр анимации
	*/
	Sprite anim(); 

	/*
	* Перемещает птицу по оси х со скоростью speed
	*/
	void move(float speed);

	/*
	* Возвращает область взаимодействия
	*/
	Rect<float> getRect() const;

	/*
	* Возвращает координаты птицы
	*/
	Vector2<float> getXY() const;
};
