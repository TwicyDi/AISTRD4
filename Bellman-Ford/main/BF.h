#pragma once
#include <string>
#include "map.cpp"

using namespace std;


void read_file(map<string>*);
int** create_graph_matrix(map<string>);
string find_way(int**, size_t, int, int, int&);
void showing_the_best_way(string path, map<string> city);