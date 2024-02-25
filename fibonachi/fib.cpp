#include "fib.hpp"
#include <omp.h>


int fib(int n) {
    if (n < 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib_par(int n) {
    if (n < 2) 
        return 1;
    int x, y;
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            x = fib_par(n - 1);
            #pragma omp section
            y = fib_par(n - 2);
        }
    }
    return x + y;
}

int fib_par_wise(int n, int nt) { 
    if (n < 2) 
        return 1;
    if (nt < 2) 
        return fib(n);
    int x, y;
    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            x = fib_par_wise(n - 1, nt);
            #pragma omp section
            y = fib_par_wise(n - 2, nt - nt / 2);
        }
    }
    return x + y;
}
