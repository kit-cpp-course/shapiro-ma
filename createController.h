#pragma once
#include "gameController.h"

class createContoller {
public:

	/*
	* Возвращает указатель на экземпляр реализации gameController'а
	*/
	virtual gameController * create() = 0;
};