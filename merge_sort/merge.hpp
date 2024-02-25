void sort(int* a, int n);

void sort_par_simple(int *a, int n);

/**
 * Сотрировка слиянием in-place
 * @param a массив для сортировки
 * @param n размер массива
 * @param nt максимальное количество потоков для параллеливания
*/
void sort_par_wise(int* a, int n, int nt);
