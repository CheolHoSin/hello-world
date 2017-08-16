#include "quick_sort.h"

int* quicksort(const int *arr, const int len) {
	int* result = new int[len];

	for (int i = 0; i < len; i++) {
		result[i] = arr[i];
	}

	_quicksort(result, 0, len-1, MODE == 0 ? simple_partition : hoare_partiion);

	return result;
}
void _quicksort(int *arr, const int p, const int r, partition func) {
	if (p >= r) return;

	int q = func(arr, p, r);

	_quicksort(arr, p, q - 1, func);
	_quicksort(arr, q+1, r, func);
}

int simple_partition(int* arr, const int p, const int r) {

	int x = arr[r];
	int i = p-1;
	int tmp = 0;

	for (int j = p; j < r; j++) {
		if (arr[j] <= x) {
			i++;

			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	int part = i + 1;

	arr[r] = arr[part];
	arr[part] = x;

	return part;
}
int hoare_partiion(int *arr, const int p, const int r) {
	int x = arr[p];
	int i = p;
	int j = r+1;
	int tmp = 0;

	while (true) {
		while (--j > p && arr[j] >= x);
		while (++i < r && arr[i] <= x);

		if (i >= j) break;

		tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	}



	arr[p] = arr[j];
	arr[j] = x;

	return j;
}