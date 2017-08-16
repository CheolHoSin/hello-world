#define MODE 1
//MODE 0: simple quick sort
//MODE 1: hoare quick sort

typedef int(*partition)(int*, const int, const int);

int* quicksort(const int *arr, const int len);
void _quicksort(int *arr, const int p, const int r, partition func);

int simple_partition(int* arr, const int p, const int r);
int hoare_partiion(int *arr, const int p, const int r);