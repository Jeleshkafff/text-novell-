#pragma once

#include "MainInventoryFunctions.h"

// ��������� ��� ����������� ���� ���������
struct inventory_menu
{
	// ����������, ������������ ����� ��������
	int action;
	// ����������, ������������ �����
	const char *text;
};


// �������, ������������ ����
int show_menu(const inventory_menu *m, int max_item);

// ������� ������ ���������, ������� ��� ���� � ���������
void show_items();

// ������� ���������������� (����� �� �����)
void find_items();

// ������� ������������� ���������
void use_items();

// ������, ������������ �������� ��������� � ���� (���������� � ��������� �������� ���������)
void changes();