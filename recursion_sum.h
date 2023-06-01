#pragma once
#include <vector>
using namespace std;
template<typename T>
T rc_sum(vector<T>* list)
{
	if (list->size() == 0) return 0;
	else return list->at(0) + rc_sum(new vector<T>(list->begin() + 1, list->end()));
}

