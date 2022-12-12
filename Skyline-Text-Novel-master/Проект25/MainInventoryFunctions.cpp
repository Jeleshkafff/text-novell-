#include "MainInventoryFunctions.h"


// ������� ��������
int inventory()
{
	system("color 3");
	// ������� ��� ���� � ���������
	inventory_menu menu[] =
	{
		{ 1, "����������� ����������" },
		{ 2, "����� ���������" },
		{ 3, "������������ �������"},
	};
	// ��������� �������� ����� ��� �����-������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������ ��������
	int variant;
	do
	{
		// ����� ����
		variant = show_menu(menu, 3);
		switch (variant)
		{
			// ���������� ���������� ���������
		case 1:
			cout << "\n" << "����������:" << "\n" << endl;
			show_items();
			break;
			// ���������� ����� �� ���������
		case 2:
			cout << endl;
			find_items();
			break;
			// ��������� ������������ ����� ��������
		case 3:
			cout << endl;
			use_items();
			break;
			// �������� �� ������
		default:
			cerr << "�� ������� �������� �������" << endl;
		}
		// ��� ������ 0 ���������� �����
	} while (variant != 0);
	system("cls");
	// ����� � ����
	if (MainHero.game == false)
	{
		pointToMenuShop();
		moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3);
	}
	// ������� ��������
	return 0;
}

