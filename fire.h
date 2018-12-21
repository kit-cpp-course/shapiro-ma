#pragma once
#include "stdafx.h"
//#include "dragon.h"

class fire {

	/*
	* Текстура огня
	*/
	Texture texture;

	/*
	* Прямоугольная область взаимодействия
	*/
	Rect<float> bound;

	/*
	* Координаты огня
	*/
	Vector2<float> position;
public:

	/*
	* Основной конструктор класса, принимающий положение объекта, создающего огонь
	*/
	fire(const Vector2<float> position);
	
	/*
	* Возвращает кадр перемещённого объекта
	*/
	Sprite shoot(float speed);
	
	/*
	* Возвращает область взаимодействия
	*/
	Rect<float> getRect() const;

	/*
	* Возвращает координату х
	*/
	float getX() const;
};