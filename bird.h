#pragma once
#include "stdafx.h"

class bird {

	/*
	* ����� ������������ ������ ����� ��������
	*/
	Clock frametime;

	/*
	* ������������� ������� ������ ����� ��������
	*/
	IntRect rect;

protected:
	/*
	* �������� �����
	*/
	Texture texture;

	/*
	* ������������� ������� �������������� � ��������
	*/
	Rect<float> bound;

	/*
	* ������, ���������� ���������� �����
	*/
	Vector2<float> position;
public:
	/*
	* �������� �����������, ����������� ���������� ���������� ��������� �����
	*/
	bird(float x, float y);


	/*
	* ���������� ��������� ���� ��������
	*/
	Sprite anim(); 

	/*
	* ���������� ����� �� ��� � �� ��������� speed
	*/
	void move(float speed);

	/*
	* ���������� ������� ��������������
	*/
	Rect<float> getRect() const;

	/*
	* ���������� ���������� �����
	*/
	Vector2<float> getXY() const;
};
