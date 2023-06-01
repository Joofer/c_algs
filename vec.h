#pragma once
#include <vector>
#include <string>
using namespace std;
template <typename T>
string vec_to_str(vector<T>* vec)
{
	string str = "";
	for (size_t i = 0; i < vec->size(); i++) str.append("[" + to_string(i) + "]" + "\t");
	str.append("\n");
	for (auto item : *vec) str.append(to_string(item) + "\t");
	str.append("\n");
	return str;
}
