#include "Loading.h"
#include "Skyline.h"



void load_game()
{
	bool IsLoadingSuccessful;
	// �������� ����� ��� ������
	ifstream in3(SaveGameFileName);
	// �������� �� ������� �����
	if (!in3)
	{
		// ���� ���� �� ���������� - ���������� ��������� �������� false
		IsLoadingSuccessful = 0;
	}
	else
	{
		// ������ �������� ���������� �� ����� � ������ �� � ������
		for (int i = 0; i < 11; i++)
		{
			in3 >> MainHero.inventory_items[i];
			IsLoadingSuccessful = 1;
		}
		// �������� �����
		in3.close();
	}
	
	// ������� �������� � ������� � ����� ������ ����
	MainHero.Money = atoi(MainHero.inventory_items[0].c_str());
	MainHero.Life = atoi(MainHero.inventory_items[1].c_str());
	MainHero.location = atoi(MainHero.inventory_items[2].c_str());
	
	system("pause");
}



// ������� ���������� ���������� �����, ��������, ������� ������, ���������
void save()
{
	bool IsSavingSuccessful;
	// �������� ����� ��� ������
	ofstream out0(SaveGameFileName);
	// �������� �� ������� �����
	if (!out0)
	{
		// ���� ���� �� ���������� - ���������� ��������� �������� false
		IsSavingSuccessful = 0;
	}
	else
	{
		// ������ �������� ���������� � ����
		out0 << MainHero.Money << endl;;
		out0 << MainHero.Life << endl;;
		out0 << MainHero.location << endl;;

		// ������ �������� ���������� � ����
		for (int i = 3; i < 11; i++)
		{
			out0 << MainHero.inventory_items[i]<< endl;
			IsSavingSuccessful = 1;
		}
		// �������� �����
		out0.close();
	}
}


// ������� �������� ����� ����
void new_game()
{
	bool IsLoadingNewGameSuccessful;
	// �������� ����� ��� ������
	ifstream in0(NewGameFileName);
	// �������� �� ������� �����
	if (!in0)
	{
		// ���� ���� �� ���������� - ���������� ��������� �������� false
		IsLoadingNewGameSuccessful = 0;
	}
	else
	{
		// ������ �������� ���������� �� �����
		for (int i = 0; i < 11; i++)
		{
			in0 >> MainHero.inventory_items[i];
			IsLoadingNewGameSuccessful = 1;
		}
		// �������� �����
		in0.close();
	}
	// ������� �������� � ������� � ����� ������ ����
	MainHero.Money = atoi(MainHero.inventory_items[0].c_str());
	MainHero.Life = atoi(MainHero.inventory_items[1].c_str());
	MainHero.location = atoi(MainHero.inventory_items[2].c_str());
	
}
