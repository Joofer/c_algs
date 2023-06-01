#include "recursion_sum.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(int argc, char** arhv)
{
	vector<uint32_t> array = {2, 4, 6};
	cout << rc_sum<uint32_t>(&array) << endl;
}
