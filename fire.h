#pragma once
#include "stdafx.h"
//#include "dragon.h"

class fire {

	/*
	* �������� ����
	*/
	Texture texture;

	/*
	* ������������� ������� ��������������
	*/
	Rect<float> bound;

	/*
	* ���������� ����
	*/
	Vector2<float> position;
public:

	/*
	* �������� ����������� ������, ����������� ��������� �������, ���������� �����
	*/
	fire(const Vector2<float> position);
	
	/*
	* ���������� ���� ������������� �������
	*/
	Sprite shoot(float speed);
	
	/*
	* ���������� ������� ��������������
	*/
	Rect<float> getRect() const;

	/*
	* ���������� ���������� �
	*/
	float getX() const;
};