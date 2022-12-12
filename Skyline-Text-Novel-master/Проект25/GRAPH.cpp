#include "Graph.h"

void GRAPH()
{
	Edge *e = new Edge[EDGES];						// �������� ������ ��� ������ �������� ���� Edge 
	Node *n = new Node[VERTEXNUM];					// �������� ������ ��� ������ �������� ���� Node
	Graph G = new graph;							//�������� ������ ��� ����

	for (int fir = DEFAULT; fir < EDGES; fir++)		//���������� �����
	{
		e[fir].Choice = new char[LengthChoice];		//� ������ ��������� ������� �������� �������� ������ ��� ������ ���� char
	}
	for (int sec = DEFAULT; sec < VERTEXNUM; sec++)	//���������� �������
	{
		n[sec].Story = new char[LengthStory];		//� ������ ��������� ������� �������� �������� ������ ��� ������ ���� char ����� 14
	}

	G = GRAPHinit(G);								//������� ���������� ��������� ����� 
	GRAPHfilling(e);								//������� ���������� ��������� � �������� ������ � �����, ����������� ���������� �� �����
	Changeherofill(n);
	addEdge(e, G);									//������� ���������� ������ ��������� ����� � ������ ������� 
	Add�hoice(e);									//������� ���������� ������� ������� ������ �� ������, ����������� ���������� �� �����
	AddStory(n);									//������� ���������� ������� ������� �������, ����������� ���������� �� �����
	Selection(G, e, n);								//������� ��������� ������ � ������ ���� ���� �� �����

	//������� ������, ������� ��� ������� 
	delete e;
	delete n;
	delete G;
	system("cls");
}


Graph GRAPHinit(Graph G)			//������� ���������� ��������� �����
{
	G->V = VERTEXNUM;							//������� � ���� ��������� V ����������� ���-�� ������
	G->adj = new list<int>[VERTEXNUM];			//�������� ������ �� ������ ������
	return G;
}

int GRAPHfilling(Edge *e)			//������� ���������� ��������� � �������� ������ � �����, ����������� ���������� �� �����
{
	ifstream Txtgraph;							//��������� ���������� 
	Txtgraph.open("Txtgraph.txt");				//��������� ���� ��� ������
	if (Txtgraph.fail()) { return 1; }			//���������, �������� �� ����
	while (!Txtgraph.eof())						//��������� �� �����, ���� �� �� ��������
	{
		for (int i = 0; i <EDGES; i++)			//�������� ����
		{
			Txtgraph >> e[i].v >> e[i].w>> e[i].number;		//��������� � ���� ��������� �������� ������ �� �����
		}
	}
	Txtgraph.close();							//��������� ������������ ����
	return 0;
}

int Changeherofill(Node *n)
{
	ifstream ChangeHero;							//��������� ���������� 
	ChangeHero.open("ChangeHero.txt");				//��������� ���� ��� ������
	if (ChangeHero.fail()) { return 1; }			//���������, �������� �� ����
	while (!ChangeHero.eof())						//��������� �� �����, ���� �� �� ��������
	{
		for (int i = 0; i < VERTEXNUM; i++)			//�������� ����
		{
			ChangeHero >> n[i].changeMoney >> n[i].changeLife >> n[i].changeArmor >> n[i].changeAttack;    //��������� � ���� ��������� �������� ������ �� �����
		}						
	}
	ChangeHero.close(); //��������� ������������ ����
	return 0;
}

void addEdge(Edge *e, Graph G)		//������� ���������� ������ ��������� ����� � ������ ������� 
{
	for (int i = 0; i<EDGES; i++)					//���������� ���-�� ����� 
		G->adj[e[i].v].push_back(e[i].number);			//����� ����� ������� �������� �������
}

int Add�hoice(Edge *e)				//������� ���������� ������� ������� ������ �� ������, ����������� ���������� �� �����
{
	ifstream �hoice;							//��������� ����������
	�hoice.open("Choice.txt");					//��������� ���� ��� ������
	if (�hoice.fail()) { return 1; }			//���������, �������� �� ����
	do
	{
		for (int i = 0; i < EDGES; i++)			//�������� ����
		{
			�hoice.getline(e[i].Choice, LengthChoice);	//���������� � ��� ������ ������ �� �����
		}
	} while (!�hoice.eof());					//��������� ��� ����, ���� ���� �� ��������
	�hoice.close();
	return 0;
}

int AddStory(Node *n) //������� ���������� ������� ������� �������, ����������� ���������� �� �����
{
	ifstream Story;								//��������� ����������
	Story.open("Story.txt");					//��������� ���� ��� ������
	if (Story.fail()) { return 1; }				//���������, �������� �� ����

	for (int i = 0; i < VERTEXNUM; i++)			//�������� ����
	{
		Story.getline(n[i].Story, LengthStory, ';');	//���������� � ��� ������ ������ �� �����
	}

	Story.close();								//�������� ����� 
	return 0;
}

void endofgame()
{
	cout << "\n\n\n\n\t\t\t" << "����� ����\n";
	cout << "�����:\n";
	cout << "���-��\n";

}
//����� ����
void Selection(Graph G, Edge *e, Node *n)
{
	int z = DEFAULT;
	int listmass[3] = { 0,0,0 };
	MainHero.game = true;
	while (MainHero.game)
	{
		system("cls");
		ChangeHero(n);
		printInterBlue();
		Showstory(n, &z);

		if ((G->adj[MainHero.location].size() == DEFAULT) || (MainHero.Life < DEFAULT))
		{
			MainHero.game = false;
			system("cls");
			endofgame();
			system("pause");
			break;//
		}

		Showchoices(G, e, listmass);
		printInterGreen();
		CheckingInput(&z);

		switch (z)
		{
		case 1: {MainHero.location = listmass[0]; break; }
		case 2: {if (listmass[1] != DEFAULT) MainHero.location = listmass[1]; break; }
		case 3: {if (listmass[2] != DEFAULT) MainHero.location = listmass[2]; break; }
		case 4: {system("cls"); pointToMenuShop(); moveToMenuPoint(7, 14, Point_Shop, 9, hat_Shop, 6, 3); break; }
		case 5: {inventory(); break; }
		case 6: {exit(); break; }
		default:{}
		}

		for (int j = 0; j < 3; j++)
		{
			listmass[j] = DEFAULT;
		}
		z = DEFAULT;
	}
}

void Showstory(Node *n, int *z) //�������, ������� ������� ����� ������� �� �����
{
	if (n[MainHero.location].Story[1] != ' ') //���� ������ ������ ������� �� ������, ����� ������� ����� �������
	{
		cout << n[MainHero.location].Story; //������� �� ����� �����
		cout << endl;
		_getch();
	}
	else skeletonKey(z); //���� ������� �� �����������, ����������� ����

}

void Showchoices(Graph G, Edge *e, int *listmass) //�������, ������� ������� ������ �� ����� 
{
	int j = 0;//����������, ��� �������� ��������� ������� �� ��������
	//���� ��� �������� ��������, ���������� � ����� �������
	for (list<int>::iterator i = G->adj[MainHero.location].begin(); i != G->adj[MainHero.location].end(); i++, j++)
	{
		cout << "\t" << e[*i].Choice; //������� ���� ����� �� �����
		listmass[j] = e[*i].w; //���������� � ������ ������� �������� �� ����� ������� 
	}
}

void CheckingInput(int *z) //������� ��� �������� ������������ �����
{
	if (*z == DEFAULT) //���� z ����� ��������� �������� (0)
	{
		//���� ��� ���������� ���� � �����, �� �������� � ��������
		while (!(cin >> *z) || (cin.peek() != '\n') || (*z < 1) || (*z > 6))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������������ ����, ���������� �����" << endl;
		}
	}
}

void ChangeHero(Node *n)
{
	MainHero.Money = MainHero.Money + n[MainHero.location].changeMoney;
	MainHero.Life = MainHero.Life + n[MainHero.location].changeLife;
	MainHero.Armor = MainHero.Armor + n[MainHero.location].changeArmor;
	MainHero.Attack = MainHero.Attack + n[MainHero.location].changeAttack;

//	changes();
}