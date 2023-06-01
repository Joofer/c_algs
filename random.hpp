#include <random>
using namespace std;
template<typename T, typename N>
T uniform(T from, N to)
{
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<T> distr(from, to);
	return distr(generator);
}
