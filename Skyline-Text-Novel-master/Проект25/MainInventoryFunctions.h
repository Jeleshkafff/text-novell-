#pragma once

#include <iostream>
#include <fstream>
#include <cstdio> 
#include <cstdlib>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Menu.h"
#include "Definitions.h"
#include "Inventory.h"
#include "Loading.h"
#include "GRAPH.h"


using namespace std;

//���� � ����� ����������/��������
#define SaveGameFileName "Save1.txt"

//���� � ����� �������� ����� ����
#define NewGameFileName "New.txt"

// ������� �������� ���������
int inventory();
// ������� �������� ��������
void menu();