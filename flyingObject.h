#pragma once
#include "stdafx.h"

class flyingObject {

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
	* Текстура объекта
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
	* Основной конструктор, принимающий координаты начального положения объекта
	*/
	flyingObject(float x, float y, std::string texturePath, Rect<float> bound);


	/*
	* Возвращает следующий кадр анимации
	*/
	Sprite anim();

	/*
	* Перемещает объект по оси х со скоростью speed
	*/
	virtual void move(float speed)=0;

	/*
	* Возвращает область взаимодействия
	*/
	Rect<float> getRect() const;

	/*
	* Возвращает координаты птицы
	*/
	Vector2<float> getXY() const;
};