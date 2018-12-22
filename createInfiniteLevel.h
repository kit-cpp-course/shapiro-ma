#pragma once
#include "createController.h"
#include "infiniteLevel.h"

class createInfiniteLevel : public createContoller {
public:

	/*
	* Возвращает указатель на экземпляр класса infiniteLevel
	*/
	gameController * create() {
		return new infiniteLevel();
	}
};