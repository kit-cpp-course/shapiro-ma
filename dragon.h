#pragma once
#include "bird.h"

class dragon : public bird{
public:

	/*
	* �������� ����������� ������
	*/
	dragon();

	/*
	* ���������� ����� �� ��� � �� ��������� speed
	*/
	void move(float speed);
}; 
