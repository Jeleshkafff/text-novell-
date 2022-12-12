
#include <iostream>
#include "Menu.h"
#include "Definitions.h"
#include <stack>
#include "Skyline.h"
using namespace std;

/*���� ��������� ������ ����� ������, ����� �������� � ������ �������� */
struct node
{
	int data;
	struct node* left, *right;
};

/*��������������� �������, ������� �������� ����� ���� ��� ������ �
NULL ��� ���������� ����� � ������. */
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

// ����������� ������� ��� ������ �������� x � �������� �������� ������
bool iterativeSearch(node *root, int x)
{
	cout << "1. ����� �������. "<<endl;
	cout << "2. ���� "<<endl;
	cout << "3. ����� "<<endl;
	cout << "4. ������ "<<endl;
	cout << "5. ������ "<<endl;
	cout << "6. ��� "<<endl;
	cout << "7. ���� "<<endl;
	cout << "�������� ����������� ��� �������: "<<endl;
	cin >> MainHero.x;
	// Base Case
	if (root == NULL)
		return false;

	// ������� ������ ���� � �������� ��������� � ����  root
	stack<node *> nodeStack;
	nodeStack.push(root);

	// ����������� ����� ���������� ��� ������ x
	while (nodeStack.empty() == false)
	{
		// ��. ������� ������� �� ����� � ���������, ��������� �� �� � x
		struct node *node = nodeStack.top();
		if (node->data == MainHero.x)
			return true;
		nodeStack.pop();

		// ���������� ������ � ����� �������� �������� �������������� ���� � ����
		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}

	return false;
}


int matreein()
{
	setlocale(LC_ALL, "Russian");
	int height = 0;
	struct node*NewRoot = NULL;
	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(7);
	root->right->left = newNode(5);
	if (!iterativeSearch(root, MainHero.x))
	{
		cout << "Not Found\n";
	}
	do
	{
		switch (MainHero.x)

		{
			char c;
			case 1:
			cout <<"����� �������"<<endl;
			cout <<"���� ������ ������ ������� *"<<endl ;
			cin>> c;
			if ((c=='*')&&(MainHero.Money - Shop[0].position >= 0))
				{
				MainHero.Money = MainHero.Money - Shop[0].position;
					MainHero.Life = MainHero.Life + Shop[0].of;
					Inventory(MainHero.positionOfShop);
		        }
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, FOURTEEN, Point_Shop, 9, hat_Shop, 6, 3);
				break;
		case 2:
			cout << "����" << endl;
			cout << "���� ������ ������ ������� *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[1].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[1].position;
				MainHero.Armor = MainHero.Armor + Shop[1].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6,1);

			break;
		case 3:
			cout << "�����" << endl;
			cout << "���� ������ ������ ������� *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[2].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[2].position;
				MainHero.Armor = MainHero.Armor + Shop[2].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 4:
			cout << "������" << endl;
			cout << "���� ������ ������ ������� *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[3].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[3].position;
				MainHero.Armor = MainHero.Armor + Shop[3].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 5:
			cout << "������" << endl;
			cout << "���� ������ ������ ������� *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[4].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[4].position;
				MainHero.Armor = MainHero.Armor + Shop[4].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 6:
			cout << "���"<<endl;
			cout << "���� ������ ������ ������� *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[5].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[5].position;
				MainHero.Armor = MainHero.Armor + Shop[5].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
		case 7:
			cout << "���" << endl;
			cout << "���� ������ ������ ������� *" << endl;
			cin >> c;
			if ((c == '*') && (MainHero.Money - Shop[6].position >= 0))
			{
				MainHero.Money = MainHero.Money - Shop[6].position;
				MainHero.Attack = MainHero.Attack + Shop[6].of;
				Inventory(MainHero.positionOfShop);
			}
			system("cls");
			pointToMenuShop();
			moveToMenuPoint(SEVEN, NINE, Point_MainMenu, 4, hat_Skyline, 6, 1);

			break;
			// �������� �� ������
		default:
			cerr << "�� ������� �������� �������" << endl;
		}
		// ��� ������ 0 ���������� �����
	} while ((MainHero.x != 0) & (MainHero.x>7)& (MainHero.x<0));
	return 0;
}
	
 

/*������� ���������� �������� true, ���� ������ ������������� else false
������ �������� - ��� ������ ������.
������� ��� ����� �������� ��������� �� ������ �� ���������
��� 0. �� ����� ����� �������� ������� ��� ���� �������� */
bool isBalanced(struct node *root, int* height)
{
	/*Lh->������ ������ ���������
		Rh->������ ������� ��������� */
	int lh = 0, rh = 0;

	/*L ����� �������, ���� ����� ��������� ��������������
		� r ����� �������, ���� ������ ��������� �������������� */
	int l = 0, r = 0;

	if (root == NULL)
	{
		*height = 0;
		return 1;
	}

	/*�������� ������ ������ � ������� ����������� � lh � rh
		� ��������� ������������ �������� � l � r */
	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	/*������ �������� ���� - ��� ������������ ������ ������ �
		������ ���������� ���� 1 */
	*height = (lh > rh ? lh : rh) + 1;

	/*���� ������� ����� �������� ����� � ������
		����������� ������ 2, ����� ���� ���� �� �������������
		������� ���������� 0 */
	if ((lh - rh >= 2) || (rh - lh >= 2))
		return 0;

	/*���� ���� ���� �������������, � ����� � ������ ����������
		����������������, � ����� ���������� true */
	else return l&&r;
}