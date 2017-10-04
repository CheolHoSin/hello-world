#include "counter_sort.h"
#include <stdlib.h>

int* counter_sort(int* arr, const int len) {
	int* res = new int[len];
	int max = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i] < 0) { return nullptr; }
		if (arr[i] > max) { max = arr[i]; }
	}
	max += 1;

	if (max > 10000) { return nullptr; }

	int* counter = (int *)calloc(max, sizeof(int));

	for (int i = 0; i < len; i++) {
		counter[arr[i]] += 1;
	}

	for (int i = 1; i < max; i++) {
		counter[i] += counter[i - 1];
	}

	for (int j = len - 1; j >= 0; j--) {
		res[counter[arr[j]]-1] = arr[j];
		counter[arr[j]] -= 1;
	}

	free(counter);

	return res;
}