#include <chrono>
#include <omp.h>
#include <iostream>

#include "merge.hpp"
int main()
{
    omp_set_nested(1);
	int nt = omp_get_max_threads();
	std::cout << "Max num threads = " << nt << std::endl;
	int N = 5000000;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = rand()/100;
	}
	auto begin = std::chrono::high_resolution_clock::now();
	sort_par_wise(a, N, nt);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout.precision(15);
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000. << std::endl;
//    for (int i = 0; i != N; i++)
//    {
//        std::cout << a[i] << std::endl;
//    }
}
