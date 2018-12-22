#pragma once
#include "stdafx.h"
#include "flyingObject.h"

class bird : public flyingObject{
public:

	/*
	* Основной конструктор класса, принимающий расположение птицы
	*/
	bird(float x, float y);

	/*
	* Перемещает птицу по оси х со скоростью speed
	*/
	void move(float speed);
};
