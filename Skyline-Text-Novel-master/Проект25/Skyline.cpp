#include "Skyline.h"
#include "RunFunctions.h"
#include "Menu.h"
#include "Minigames.h"
#include "MainInventoryFunctions.h"

// ������� �������� ������ ����
int main()
{
	// ��������� �������� �����
	setlocale(LC_ALL, "Russian");
	// ����� �������� ����
	menu();
	// ������� ������ ������
	if (MainHero.Life <= 0)
	{
		// �������� ������
		system("cls");
		// ���������� � ������ ������
		cout << "�� ������!!!" << endl;
	}
}

// ������� ������ �� ����
void exit()
{
	// �������� ������
	system("cls");
	// ������ �� ����������� ������ � �������  ����� �� ����
	cout << "�� ������������� ������ ����� (+/-)?" << endl;
	// ���������� � ������ ���������� ��� ������
	char a;
	cin >> a;
	// ������� ������
	if (a == '+')
	{
		// ����������
		save();
		// ����������� ������ ���������
		exit(0);
	}
}
