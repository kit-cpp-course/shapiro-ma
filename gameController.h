#pragma once
#include "stdafx.h"
#include "bird.h"

class gameController {
protected:
	/*
	* ������ ����
	*/
	short width;

	/*
	* ������ ����
	*/
	short height;

	/*
	* �������� ����
	*/
	Texture background;


	/*
	* �������� �����
	*/
	Font font;

	/*
	* ������ ������� � ������� ������ ����
	*/
	Clock cl;

	/*
	* ��������� ��������
	*/
	Text setText(std::string content, short size, Vector2<short> position = { 0,0 }, Color color = Color::Black);
public:

	/*
	* �������� ����������� ������, ����������� ������, ������ ����, ���� � ����������� ���� � ������
	*/
	gameController(short width, short height, std::string backgroundPath, std::string fontPath);

	/*
	* ��������� ����
	*/
	virtual void drawBG(RenderWindow & window) = 0;

	/*
	* ��������� ������, ��������� ������ ������
	*/
	virtual void genLvl(std::vector<bird> & enemies) = 0;

	/*
	* ���������� �������, ���������� ���������� � ���������� �����
	*/
	virtual Text score() = 0;

	/*
	* ������������ �����
	*/
	virtual void printText(RenderWindow & window) = 0;

	/*
	* ���������� ������ ����
	*/
	short getWidth() const;

	/*
	* ���������� ������ ����
	*/
	short getHeight() const;
};