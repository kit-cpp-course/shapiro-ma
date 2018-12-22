#pragma once
#include "flyingObject.h"

class dragon : public flyingObject{
public:

	/*
	* Основной конструктор класса
	*/
	dragon();

	/*
	* Перемещает птицу по оси х со скоростью speed
	*/
	void move(float speed);
}; 
