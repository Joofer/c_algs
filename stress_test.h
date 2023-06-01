#pragma once
#include <thread>
#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
#include <cstring>
#include "vec.h"
#include "random.hpp"
using namespace std;
template<typename T>
vector<T> rand_arr(size_t num_items, long min, T max)
{
	vector<T> arr(num_items);
	for (size_t i = 0; i < num_items; i++)
		arr[i] = uniform(min, max);
	return arr;
}
template<typename T>
void reliable_sort(vector<T>* array)
{
	sort(array->begin(), array->end());
	cout << "sorted with std::sort\n";
}
template<typename T>
void stress_test_sort(size_t num_iters, size_t max_elems, void(*alg)(vector<T>*))
{
	size_t max_elem = 100;
	vector<size_t> elem_nums = rand_arr(max_elems, 0, max_elem);
	elem_nums[0] = 0;

	long min_item = -10000000000;
	size_t max_item = 10000000000;
	int k = 0;
	for (auto elem_num : elem_nums)
	{
		try
		{
			auto arr = rand_arr<T>(elem_num, min_item, max_item);
			auto sorted_alg = arr, sorted_reliable = arr;
			
			thread t(reliable_sort<T>, &sorted_reliable);
			alg(&sorted_alg);
			cout << "sorted with *alg\n";
			t.join();
		
			if (sorted_alg != sorted_reliable)
			{
				cout << "Case failed. [elem_num: " << elem_num << "]\n"
					<< "initial:\n" << vec_to_str(&arr)
					<< "alg:\n" <<  vec_to_str(&sorted_alg)
					<< "reliable:\n" << vec_to_str(&sorted_reliable);
				return;
			}
			if (k % 10 == 0)
			{
				cout << "Passed " << k << " iterations.\n";
			}
			k++;
		}
		catch (std::exception e)
		{
			cout << "exception: " << e.what() << endl;
		}
	}

	cout << "Stress test complete!\n";
}
