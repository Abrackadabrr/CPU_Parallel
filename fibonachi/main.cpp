#include <iostream>
#include "fib.hpp"
#include <omp.h>

int main() {
    int n = 42;
    omp_set_nested(1);
    int nt = omp_get_max_threads();
    std::cout << "Max num threads = " << nt << std::endl; 
    std::cout << "Fork bomb exploding..." << std::endl;
    std::cout << fib_par(n) << std::endl;
    return 0;
}
