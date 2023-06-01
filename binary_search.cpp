#include <iostream>
#include "vec.h"
using namespace std;

class bs
{
	public:
		bs()
		{}
		static int binary_search(vector<int>* array, int item)
		{
			int hi = array->size() - 1;
			int lo = 0;

			while (hi >= lo)
			{
				int mid = lo + (hi - lo) / 2;

				if (array->at(mid) > item) hi = mid - 1;
				else if (array->at(mid) < item) lo = mid + 1;
				else return mid;
			}
			
			return -1;
		}
};

int main()
{
	vector<int> arr = {1, 3, 5, 7, 9};
	cout << vec_to_str(&arr) << endl;

	int item = 7;
	cout << item << " is on position " << bs::binary_search(&arr, item) << endl;
	item = 0;
	cout << item << " is on position " << bs::binary_search(&arr, item) << endl;
	item = 1;
	cout << item << " is on position " << bs::binary_search(&arr, item) << endl;
}
