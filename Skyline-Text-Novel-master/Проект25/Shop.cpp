#pragma once//������������ ��� ��������� ����������� ��������

#include "Menu.h"//����������� �������� ��������������(���������)
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include "Definitions.h"
#include <string> 
#include <fstream>
#include "MainInventoryFunctions.h"
#include "Skyline.h"
#include "Menu.h"


fstream fout(SaveGameFileName, ios::in | ios::out | ios::ate);



int a = 9;
int b = 25;

 hero MainHero;
 item shop;

 

using namespace std;
/*
void Read(char **a, int rowsCount, int columnsCount, char *filename)
{
	//char mass[9][56];
	//char str[305];
	//char *print_array = (char*)mass;
	
	ifstream txt(filename); // �������� �����
	for (int y = 0; y < rowsCount; y++) // ���� ������������ ������ ������ �� �����
	{
		txt.getline(str, sizeof(str)); // ��������� ������ �� �����
		for (int x = 0; x <= columnsCount; x++) // ������ ������� �� ������������ ������� �����
			a[y][x] = str[x];
	}
	txt.close(); // �������� �����
	for (int r = 0; r <rowsCount; r++)//����� ������� ���� char(����� ������ ����) ������� ������(�� ������ �������)
	{
		for (int c = 0; c < columnsCount; c++)
		{
			cout <<a[r][c];// ����� �������� ������� �� �����
		}
		cout << "\n\t";// ������, ���������

	}
}*/

void Print( int rowsCount, int columnsCount, char *filename)
{
	system("color 3");

	char mass[9][56];
	char str[305];
	char *print_array = (char*)mass;
	
	ifstream txt(filename); // �������� �����
	for (int y = 0; y < rowsCount; y++) // ���� ������������ ������ ������ �� �����
	{
		txt.getline(str, sizeof(str)); // ��������� ������ �� �����
		for (int x = 0; x <= columnsCount; x++) // ������ ������� �� ������������ ������� �����
			mass[y][x] = str[x];
	}
	txt.close(); // �������� �����

	for (int r = 0; r <rowsCount; r++)//����� ������� ���� char(����� ������ ����) ������� ������(�� ������ �������)
	{
		for (int c = 0; c < columnsCount; c++)
		{
			cout << mass[r][c];// ����� �������� ������� �� �����
		}
		cout << "\n\t";// ������, ���������

	}
	

}
void Print( int rowsCount, int columnsCount, int positionOfShop, char *filename)
{
	system("color 3");

	char mass[9][56];
	char str[305];
	char *print_array = (char*)mass;

	ifstream txt(filename); // �������� �����
	for (int y = 0; y < rowsCount; y++) // ���� ������������ ������ ������ �� �����
	{
		txt.getline(str, sizeof(str)); // ��������� ������ �� �����
		for (int x = 0; x <= columnsCount; x++) // ������ ������� �� ������������ ������� �����
			mass[y][x] = str[x];
	}
	txt.close(); // �������� �����

	for (int r = 0; r < rowsCount; r++)//����� ������� ���� char(����� ������ ����) ������� ������(�� ������ �������)
	{
		for (int c = 0; c < columnsCount; c++)
		{

			cout << mass[r][c];// ����� �������� ������� �� �����
		}

		cout << "\n        ";// ������, ���������
	}
	stand(5, positionOfShop, 7, "-->");
}

void pointToMenuShop()
{// ����������� ������� ������ �����
		
		//Print(MainHero.rowsCount, MainHero.columnsCount,"Shop.txt");// ����������� ������� ������ �����
		//Print( a, b, MainHero.positionOfMenu,  "Items.txt");
		display_draw(hat_Shop, 6,52);
		display_draw(Point_Shop, 9, 52);
		strelka(MainHero.positionOfMenu);
		printMeasure();		
}

void moveToMenuPoint(int a, int b,  char ** Massive, int y, char ** Massive2, int y2,int proverka)
{
	bool f = true; //���������� ����������, ���������� �� ������������� ����� �� �����

	while (f == true){//���� �� ����� ����������
		int code = _getch();//������������� ������� �������
		switch (code)//�� �����������
		{
		case DOWN_ARROW:
			if (MainHero.positionOfMenu<b)//��������� ������ �� �������
				MainHero.positionOfMenu++;//���������� ��� ������������ �����������(������� ����� ������ ����) ���������� �� 1 ��� �������� ����������� �������
			stand(0, 0);
			//system("cls");
			display_draw(Massive2, y2, 52);
			display_draw(Massive,y,52);	
			
			strelka(MainHero.positionOfMenu);

			break;

		case UP_ARROW:
			if (MainHero.positionOfMenu>a)//��������� ������ �� �������
				MainHero.positionOfMenu--;//���������� ��� ������������ �����������(������� ����� ������ ����) ���������� �� 1 ��� �������� ����������� �������
			stand(0, 0);
			//system("cls");
			
			display_draw(Massive2, y2, 52);
			display_draw(Massive, y,52);
			strelka(MainHero.positionOfMenu);
		
			break;

		case ENTER://����� ������, ����������� �������
			if (proverka == 1){ userSelection(MainHero.positionOfMenu); }
			// �������� ��������� ������� � ������� ������ ��������, ������� ����������� ��� ������ ����
			if (proverka == 2){ userSelection2(MainHero.positionOfMenu); }
			if (proverka == 3){ userSelectionShop(MainHero.positionOfMenu); }
			f = false;//���������� �����, ����� �� ����
			break;

		case 8:
			system("cls");
			fout.close();
			inventory();
			
			f = false;
			break;

		case 32:
			system("cls");
			fout.close();
			matreein();			
			f = false;
			break;
		}
	}
}

void userSelectionShop(int Cur)
{
	stand(0, 0);
	int p = Cur;
	switch (Cur)
	{
	case 7:
		if (MainHero.Money - Shop[0].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[0].position;
			MainHero.Life = MainHero.Life + Shop[0].of;
			Inventory(p);
		}		
		pointToMenuShop();
		moveToMenuPoint(7, 14,Point_Shop, 9, hat_Shop,6,3);
		break;
	case 8:
		if (MainHero.Money - Shop[1].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[1].position;
			MainHero.Armor = MainHero.Armor + Shop[1].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 9:
		if (MainHero.Money - Shop[2].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[2].position;
			MainHero.Armor = MainHero.Armor + Shop[2].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 10:
		if (MainHero.Money - Shop[3].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[3].position;
			MainHero.Armor = MainHero.Armor + Shop[3].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 11:
		if (MainHero.Money - Shop[4].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[4].position;
			MainHero.Armor = MainHero.Armor + Shop[4].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 12:
		if (MainHero.Money - Shop[5].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[5].position;
			MainHero.Armor = MainHero.Armor + Shop[5].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 13:
		if (MainHero.Money - Shop[6].position >= 0) {
			MainHero.Money = MainHero.Money - Shop[6].position;
			MainHero.Attack = MainHero.Attack + Shop[6].of;
			Inventory(p);
		}
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
		break;
	case 14:
		system("cls");
		if (MainHero.game == false)
		{
			pointToMenu();//� ������ ������� ������� �����, ����� �����������
			moveToMenuPoint(7, 9, Point_MainMenu, 4, hat_Skyline, 6, 1);
			fout.close();
		}
		break;
	}
}

void printMeasure()

{
	stand(58, 0, 7, "                        ");
	stand(58, 0, 7, MainHero.Life, " ��");
	stand(64, 0, 7, MainHero.Armor, " ��");
	stand(68, 0, 7, MainHero.Attack," ��");
	stand(73, 0, 7, MainHero.Money," $");

}

void Inventory(int p)
{	
	switch (p)
	{
	case 7:	
		MainHero.inventory_items[5] = "�����_�������";
		break;
	case 8:		
		MainHero.inventory_items[7] = "����";
		break;
	case 9:		
		MainHero.inventory_items[4] = "�����";
		break;
	case 10:	
		MainHero.inventory_items[8] = "������";
		break;
	case 11:
		MainHero.inventory_items[9] = "������";
		break;
	case 12:
		MainHero.inventory_items[10] = "���";
		break;
	case 13:
		MainHero.inventory_items[3] = "���";
		break;
	}		
}