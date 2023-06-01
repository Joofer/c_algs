#pragma once
#include <vector>
using namespace std;
template<typename T>
size_t rc_max(vector<T>* list)
{
	if (list->size() == 2) return list->at(0) > list->at(1) ? list->at(0) : list->at(1);
	size_t submax = rc_max(new vector<T>(list->begin() + 1, list->end()));
	return list->at(0) > submax ? list->at(0) : submax;
}
