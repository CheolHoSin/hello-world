#include "radix_sort.h"

int get_radix_val(int a, int radix);
int power(int x, int y);
void init_arr(int* arr, const int len);

int* radix_sort(int* arr, const int len) {
	int max = 0;

	for (int i = 0; i < len; i++) {
		if (max < arr[i]) { max = arr[i]; }
	}

	int max_radix = 1;

	while (true) {
		max = max / 10;
		if (max == 0) break;

		max_radix += 1;
	}

	int* radix_sorted = arr;
	int counter[10] = { 0, };
	int* radix_arr = new int[len];

	for (int i = 1; i <= max_radix; i++) {
		for (int j = 0; j < len; j++) {
			radix_arr[j] = get_radix_val(radix_sorted[j], i);
		}

		init_arr(counter, 10);

		for (int j = 0; j < len; j++) {
			counter[radix_arr[j]] += 1;
		}

		for (int j = 1; j < 10; j++) {
			counter[j] += counter[j - 1];
		}

		int* tmp = new int[len];

		for (int j = len - 1; j >= 0; j--) {
			tmp[counter[radix_arr[j]]-1] = radix_sorted[j];
			counter[radix_arr[j]] -= 1;
		}

		if (i > 1) { delete(radix_sorted); }

		radix_sorted = tmp;
	}

	return radix_sorted;
}

int get_radix_val(int a, int radix) {
	return (a % power(10, radix)) / power(10, radix - 1);
}

int power(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res = res * x;
	}

	return res;
}

void init_arr(int* arr, const int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = 0;
	}
}