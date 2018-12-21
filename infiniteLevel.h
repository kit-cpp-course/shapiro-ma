#pragma once
#include "gameController.h"

class infiniteLevel : public gameController {

	/*
	* ����������, ����������� ��� ��������� �������� ����
	*/
	float x = 0;

	/*
	* �������, ����������� ��� ��������� �������� ����
	*/
	Sprite sp[2];

	/*
	* �������� ����������� ������
	*/
	infiniteLevel();

	/*
	* ��������� ������
	*/
	static infiniteLevel il;
public:
	/*
	* ������� �����
	*/
	int count = 0;

	/*
	* ��������� ����������� ����
	*/
	void drawBG(RenderWindow & window);

	/*
	* ��������� ������
	*/
	void genLvl(std::vector<bird> & enemies);

	/*
	* ���������� �������, ���������� ���������� � ���������� �����
	*/
	Text score();

	/*
	* ������������ �����
	*/
	void printText(RenderWindow & window);

	/*
	* ���������� ������ �� ��������� ������
	*/
	static infiniteLevel & instance();
};