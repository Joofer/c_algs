#include "selection_sort.h"
#include "stress_test.h"
using namespace std;
int main()
{
	stress_test_sort<int>(1000, 1000, &ss::selection_sort<int>);
}
