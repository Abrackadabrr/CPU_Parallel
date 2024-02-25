#include "merge.hpp"

void merge(int *a, int *b, int *c, int n, int n1, int n2) {
    int i = 0;
	int j = 0;
	for (int r = 0; r < n; r++)
	{
		if (i >= n1 && j < n2)
			{
				a[r] = c[j];
				j++;
			} 
		if (j >= n2 && i < n1)
			{
				a[r] = b[i];
				i++;
			}
		if (i < n1 && j < n2)
			{
				if (b[i] < c[j]) { a[r] = b[i]; i++; }
				else  { a[r] = c[j]; j++; };
			}
	}
}

void sort(int* a, int n)
{
	if (n != 1)
	{
		int n1 = n / 2; int n2 = n - n1;
		int* b = new int[n1];
		int* c = new int[n2];
		for (int i = 0; i < n1; i++)
		{
			b[i] = a[i];
		}
		for (int i = 0; i <n2; i++)
		{
			c[i] = a[i+n1];
		}
		sort(b, n1);
		sort(c, n2);
        merge(a, b, c, n, n1, n2);	
	delete[] b;
	delete[] c;
	}
}

void sort_par_simple(int* a, int n)
{
	if (n != 1)
	{
		int n1 = n / 2; int n2 = n - n1;
		int* b = new int[n1];
		int* c = new int[n2];
		for (int i = 0; i < n1; i++)
		{
			b[i] = a[i];
		}
		for (int i = 0; i <n2; i++)
		{
			c[i] = a[i+n1];
		}
		#pragma omp parallel
		{
			#pragma omp sections
			{
				#pragma omp section
				sort(b, n1);
				#pragma omp section
				sort(c, n2);
			}
		}
		merge(a, b, c, n, n1, n2);
	delete[] b;
	delete[] c;
	}
}


void sort_par_wise(int* a, int n, int nt)
{
	if (nt < 2)
		sort(a, n);
	else if (n != 1)
	{
		int n1 = n / 2; int n2 = n - n1;
		int* b = new int[n1];
		int* c = new int[n2];
		for (int i = 0; i < n1; i++)
		{
			b[i] = a[i];
		}
		for (int i = 0; i <n2; i++)
		{
			c[i] = a[i+n1];
		}
		#pragma omp parallel
		{
			#pragma omp sections
			{
				#pragma omp section
				sort_par_wise(b, n1, nt/2);
				#pragma omp section
				sort_par_wise(c, n2, nt - nt/2);
			}
		}
		merge(a, b, c, n, n1, n2);
	delete[] b;
	delete[] c;
	}
    return;
}


