﻿// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BF.h"

void main()
{
	setlocale(LC_ALL, "rus");
	map <string> city;
	read_file(&city);

	for (int i = 0; i < city.get_size(); i++)
	{
		for (int j = 0; j < city.get_size(); j++)
			cout << create_graph_matrix(city)[i][j] << ' ';
		cout << '\n';
	}

	cout << '\n';

	int min;
	int from, to;
	cout << "Введите код города отправления:" << endl;
	cin >> from;
	cout << "Введите код города прибытия:" << endl;
	cin >> to;
	find_way(create_graph_matrix(city), city.get_size(), from, to, min);

	getchar();
	getchar();
}

