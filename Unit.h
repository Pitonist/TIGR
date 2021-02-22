#pragma once
#include "stddef.h"
#include <cmath>
#include <iomanip>
#include <iostream>
class Unit
{
private:
	// ������� ��������, ��������, ����, ���������, �����, ��������� �����
	int hp, velocity, dmg, unit_cost, armor, atack_distance;
	// ���������� ����� � ����� ����� i, j
	int unit_i, unit_j;
	// ������� �� �����
	short int react_to_enemy;
	// ��������� ����
	Unit* target;
	// ���� ������ �����, ���� ����� ������
	bool selected, is_atacked;
	// ���������� �� �������� ����� ��� ������������� ����
	int distance(int start_i, int start_j, int finish_i, int finish_j);
	//���������� ������� � ������������
	struct priority_queue;
	typedef priority_queue* refs;
	struct priority_queue
	{
		int i, j, key;
		int prev_cell_value;
		refs next;
	};
	//������������� �������
	void InitPriorityQueue(refs& q); 
	// �������� ������� �� �������, true - ���-�� ����
	bool CheckPriorityQueue(refs q); 
	// �������� ������� � �������, ������������� �� ����������� ���� key
	void AddPriorityQueue(refs q, int i, int j, int key, int prev_val); 
	// ������� ������� �� �������
	void PopPriorityQueue(refs q, int &i, int &j, int &prev_val);
protected:
	// ������ ����, �������� ���������� ����� i, j
	struct way_to_target
	{
		int i, j;
	}way[500];
	int way_length;
public:
	Unit(int hp, int vel, int dmg, int cost, int armor, int distance, int i, int j);
	~Unit();
	// ����� ���� ������ ����������
	void FindTheWay(int** a, int n, int m, int start_i, int start_j, int finish_i, int finish_j);
	void PrintWay();
};

