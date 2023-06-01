#include "quicksort.hpp"
#include "vec.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	vector<uint32_t> array = {10, 5, 2, 3}, result = quicksort(array);
	cout << "before:\n" << vec_to_str(&array) << "after:\n" << vec_to_str(&result);
}
