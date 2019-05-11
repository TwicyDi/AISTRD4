#include "stdafx.h"
#include "BF.h"
#include <fstream>
#include <vector>


void read_file(map<string>*city)
{
	fstream fin;
	fin.open("input.txt", ios::in);
	string buf;
	int id = 0;
	cout << "��� � �����:" << endl;
	do
	{
		int counter = 0;
		getline(fin, buf);
		while (counter != 2)
		{
			size_t found = buf.find(';');
			if (city->insert(buf.substr(0, found), id)) // substr prints the substring from 0 to found
			{
				cout << id << "  " << buf.substr(0, found) << endl;
				id++;
			}
			buf.erase(0, found + 1); //delete elements from 0 to found+1
			counter++;
			
		}

	} while (!fin.eof()); 

	fin.close();
	cout << endl;
	cout << "������� ���:" << endl;

}

int **create_graph_matrix(map<string> city)
{
	
	int **matrix = new int*[city.get_size()];
	for (int i = 0; i < city.get_size(); i++)
		matrix[i] = new int[city.get_size()];
	for (int i = 0; i < city.get_size(); i++)
		matrix[i][i] = -1; //filling the diagonal of the matrix - 1, since one city
	fstream fin; //variable to write data from file
	fin.open("input.txt", ios::in);
	string buf;
	do
	{
		int counter = 0;
		getline(fin, buf); //write file data to buf
		size_t found = buf.find(';'); //found separator
		int column = city.find_id(buf.substr(0, found)); 
		buf.erase(0, found + 1); //cut the string to the character after the delimiter
		int row = city.find_id(buf.substr(0, buf.find(';'))); 
		found = buf.find(';');
		buf.erase(0, found + 1);
		found = buf.find(';');
		if (buf.substr(0, found) != "N/A")
			matrix[row][column] = stoi(buf.substr(0, found)); //stoi extracts a signed integer from a string
		else matrix[row][column] = -1;
		buf.erase(0, found + 1);
		if (buf.substr(0, buf.length()) != "N/A")
			matrix[column][row] = stoi(buf.substr(0, buf.length()));
		else matrix[column][row] = -1;
	} while (!fin.eof());

	fin.close();
	return matrix;
}

string find_way(int **graph_table, size_t size, int from, int to, int &min)
{
		if (from == to)
			throw out_of_range("���� � ��� �� �����");
	
	string* cities = new string[size]; 
	const int inf = 10000;
	vector<int> cost(size, inf);
	cost[from] = 0;
	for (;;)
	{
		bool flag = false;
		for(size_t i=0;i<size;i++)
			for(size_t j=0;j<size;j++)
				if ((cost[i] + graph_table[j][i] < cost[j]) && (graph_table[j][i] > 0))
				{
					cost[j] = cost[i] + graph_table[j][i];
					cities[j] = cities[i] + ';' + to_string(j);
					flag = true;
				}
		if (!flag) break;
	}
	cout << "����������� ���� " << cost[to] << endl;
	min = cost[to];
	string city;
	city += cities[from];
	city += cities[to];

	return city;
}

void showing_the_best_way(string cost, map<string> city)
{
	size_t found = cost.find(';');

	cost.erase(0, found + 1);
	while (true)
	{
		found = cost.find(';');
		if (cost.length() != 1)
			cout << city.find_city(stoi(cost.substr(0, found))) << " -> ";		
		else
		{
			cout << city.find_city(stoi(cost.substr(0, found)));
			break;
		}
		cost.erase(0, found + 1);
	}

}