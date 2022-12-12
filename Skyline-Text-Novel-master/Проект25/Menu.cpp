#pragma once//������������ ��� ��������� ����������� ��������

#include "Menu.h"//����������� �������� ��������������(���������)
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include <string> 
#include <fstream>
#include "Definitions.h"
#include "MainInventoryFunctions.h"
#include "Skyline.h"
#include "Minigames.h"
#include "GRAPH.h"

using namespace std;
char**  hat_Skyline = textures(6, 52, "Skyline.txt");
char**  hat_Shop = textures(6, 52, "Shop.txt");
char**  Point_Shop = textures(9, 52, "Items.txt");
char**  Point_MainMenu = textures(4, 52, "MainMenu.txt");
char**  Point_StartGame = textures(5, 52, "StartGame.txt");

item Shop[SEVEN] = { { LifePosion, 50, 1 }, { helmet, 100, 10 }, { armor, 200, 10 }, { boots, 300,10 }, 
{ shield,1000, 10 },{ sword, 10, 10 }, { manacles, 99, 10 } };


void pointToMenu()
{
	MainHero.positionOfMenu =SEVEN;

	display_draw(hat_Skyline, 6,52);
	display_draw(Point_MainMenu, 4,52);
	strelka(MainHero.positionOfMenu);
}
void pointToMenu2()
{
	MainHero.positionOfMenu = SEVEN;
	
	display_draw(hat_Skyline, 6, 52);
	display_draw(Point_StartGame, 5, 52);
	strelka(MainHero.positionOfMenu);
	
}

// ������������ ���� ������� ������ � �������� userSelection2 � userSelection3, ������ ��������������� ��������� ���������
void userSelection(int Cur)
{
	system("cls");//������� ������
	switch (Cur)
	{	
	case 7:pointToMenu2();//����� ������� (������ ����)
		moveToMenuPoint(SEVEN, FOURTEEN,Point_StartGame, 5,hat_Skyline,6,2);//������ ����� ����������� �� ����, � ��� �� ��� �����������
		break;
	case 8:pointToMenuShop();//����� ������� 
		moveToMenuPoint(SEVEN, FOURTEEN, Point_Shop, 9, hat_Shop,6,3);//������ ����� ����������� �� ����, � ��� �� ��� �����������
		break;	
	}
}                                                                               
void userSelection2(int Cur)
{
	system("cls");//������� ������
	switch (Cur)
	{

	case 7: cout << "����������"<<endl;// ������� � ���� ����� ������ ������ �������
		cout << "��� �������� � ���� ������� ����� �������";
		_getch();// �������� ������� �������
		system("cls");// ������� ������
		pointToMenu2();// ����������� �������
		moveToMenuPoint(SEVEN, FOURTEEN,Point_StartGame, 5, hat_Skyline, 6,2); // ����� ����� ����� �����������
		break;
	case 8: cout <<"������ ���� �������"<<endl;
		new_game();
		system("cls");// ������� ������
		GRAPH();
		pointToMenu2();// ����������� �������
		moveToMenuPoint(SEVEN, FOURTEEN, Point_StartGame, 5, hat_Skyline, 6, 2);
		break;
	case 9: cout << "���������� ����"<<endl;
		load_game();
		system("cls");// ������� ������
		GRAPH();
		pointToMenu2();// ����������� �������
		moveToMenuPoint(SEVEN, FOURTEEN, Point_StartGame, 5, hat_Skyline, 6, 2);
		break;
	case 10:
		pointToMenu();//� ������ ������� ������� �����, ����� �����������
		moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);
		break;
	}
}

void menu()
{

	system("color 3");
	setlocale(LC_ALL, "RUS");//��������� ��������� �������� �����
	pointToMenu();
	moveToMenuPoint(SEVEN, NINE,Point_MainMenu, 4, hat_Skyline, 6,1);
	


}


char** textures(int masy, int masx, const  char* fillname) // ������� �������������� ������������ ������ ��� ��������
{
	
	char **mass = new char*[masy]; // ��������� ������������ ������ ��� ��������� ������
	for (int i = 0; i < masy; i++)
		mass[i] = new char[masx];

	file_scan(mass, masx, masy, fillname); // �������� �������, ������� �������� ������ ��������� �� �����

	char** mas = mass;
	return mas; // ����������� ��������� ��������� �������
}
	
void strelka(int position)
{
	stand(4, MainHero.positionOfMenu,7, "-->");
}

void display_draw(char ** Massive,int Massive_Y, int Massive_X) // ������� - ��������� �������� � �������
{
	system("color 3");
	for (int r = 0; r < Massive_Y; r++)//����� ������� ���� char(����� ������ ����) ������� ������(�� ������ �������)
	{
		for (int c = 0; c < Massive_X; c++)
		{

			cout << Massive[r][c];// ����� �������� ������� �� �����
		}

		cout << "\n        ";// ������, ���������
	}

}

void file_scan(char **mas, int masx, int masy, const char*filename ) // ���������� ������� ��������� �� �����
{
	system("color 3");
	char* str = new char[masx + 1];
	ifstream txt(filename); // �������� �����
	for (int y = 0; y < masy; y++) // ���� ������������ ������ ������ �� �����
	{
		txt.getline(str, sizeof(char)*(masx + 1)); // ��������� ������ �� �����
		for (int x = 0; x <= masx; x++) // ������ ������� �� ������������ ������� �����
			mas[y][x] = str[x];
	}
	txt.close(); // �������� �����
	
	
	
}
