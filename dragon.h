#pragma once
#include "bird.h"

class dragon : public bird{
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
