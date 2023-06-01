#pragma once
#include <vector>
#include "random.hpp"
using namespace std;
template<typename T>
vector<T> quicksort(vector<T> array)
{
	if (array.size() < 2) return array;
	else
	{
		T* pivot = &array[0];
		vector<T> less, greater;
		for (auto i = array.begin(); i != array.end(); ++i)
		{
			if (*i < *pivot) less.push_back(*i);
			else if (*i > *pivot) greater.push_back(*i);
		}
		vector<T> result;
		result.reserve(array.size());
		less = quicksort(less);
		greater = quicksort(greater);
		result.insert(result.begin(), less.begin(), less.end());
		result.insert(result.begin() + less.size(), *pivot);
		result.insert(result.begin() + less.size() + 1, greater.begin(), greater.end());
		return result;
	}
}
