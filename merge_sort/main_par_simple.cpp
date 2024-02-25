#include "merge.hpp"
#include <chrono>
#include <omp.h>
#include <iostream>

int main()
{
	int N = 5000000;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = rand()/100;
	}
	auto begin = std::chrono::high_resolution_clock::now();
	sort_par_simple(a, N);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout.precision(15);
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000. << std::endl;
}
