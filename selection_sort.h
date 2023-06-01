#pragma once
#include <iostream>
#include <map>
#include "vec.h"
using namespace std;

class ss
{
	public:
		ss()
		{ }
		template<typename T>
		static void selection_sort(vector<T>* array)
		{
			map<size_t, bool> used; // key - index, value - is used, used to boost performance of algorithm so we do not need to delete element from array when popping min item, tekes extra space proportional to N
			for (size_t i = 0; i < array->size(); i++)
				used.insert(make_pair(i, false));

			vector<T> sorted(array->size());
			for (size_t i = 0; i < sorted.size(); i++)
				sorted[i] = pop_min(array, &used);
			*array = sorted;
		}
		template<typename T>
		static int pop_min(vector<T>* array, map<size_t, bool>* used)
		{
			size_t m = -1;
			for (size_t i = 0; i < array->size(); i++)
			{
				if (used->at(i) != true)
				{
					if (m == -1)
						m = i;
					else if (array->at(i) < array->at(m))
						m = i;
				}
			}
			used->at(m) = true;
			return array->at(m);
		}
};
