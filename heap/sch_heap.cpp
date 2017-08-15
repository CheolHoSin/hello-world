#include"sch_heap.h"
#include<stdlib.h>

struct _heap create_heap(const int MAX_SIZE) {
	struct _heap heap;
	heap.size = 0;
	heap.max_size = MAX_SIZE;
	heap.buf_size = calc_buf_size(0, MAX_SIZE);

	heap.data = new int[heap.buf_size];

	return heap;
}

struct _heap create_heap(const int* arr, const int len, const int MAX_SIZE) {
	struct _heap heap;
	heap.size = len;
	heap.max_size = MAX_SIZE;
	heap.buf_size = calc_buf_size(len, MAX_SIZE);

	heap.data = new int[heap.buf_size];
	
	for (int i = 0; i < len; i++) {
		heap.data[i] = arr[i];
	}

	build_heap(heap.data, heap.size);

	return heap;
}

int get_value(const struct _heap heap, const int pos) {
	if (pos >= heap.size) { return -1; }
	
	return heap.data[pos];
}

void set_value(struct _heap &heap, const int pos, const int value) {
	if (pos >= heap.size) return;

	int last_value = heap.data[pos];
	heap.data[pos] = value;

	if (last_value > value) {
		heapify(heap.data, heap.size, pos);
	}
	else {
		int pos_cur = pos;
		int pos_par = 0;
		int tmp = 0;
		while (pos_cur > 0) {
			pos_par = parent(pos_cur);
			if (heap.data[pos_cur] > heap.data[pos_par]) {
				tmp = heap.data[pos_cur];
				heap.data[pos_cur] = heap.data[pos_par];
				heap.data[pos_par] = tmp;
			}
			else {
				break;
			}
			pos_cur = pos_par;
		}
	}
}

void add_value(struct _heap &heap, const int value) {
	if (heap.size >= heap.max_size) return;

	heap.size += 1;
	if (heap.buf_size <= heap.size) {
		heap.buf_size = calc_buf_size(heap.size, heap.max_size);
		heap.data = (int*)realloc(heap.data, (heap.buf_size)*sizeof(int));
	}

	int pos_cur = heap.size - 1;

	heap.data[pos_cur] = value;

	int pos_par = -1;
	int tmp = -1;

	while (pos_cur > 0) {
		pos_par = parent(pos_cur);

		if (heap.data[pos_cur] > heap.data[pos_par]) {
			tmp = heap.data[pos_cur];
			heap.data[pos_cur] = heap.data[pos_par];
			heap.data[pos_par] = tmp;
		}
		else {
			break;
		}

		pos_cur = pos_par;
	}
}

void add_values(struct _heap &heap, const int* values, const int len) {
	if (heap.max_size < heap.size + len) return;

	int pos = heap.size;
	heap.size += len;
	if (heap.buf_size <= heap.size) {
		heap.buf_size = calc_buf_size(heap.size, heap.max_size);
		heap.data = (int*)realloc(heap.data, (heap.buf_size)*sizeof(int));
	}

	for (int i = 0; i < len; i++) {
		heap.data[pos+i] = values[i];
	}

	build_heap(heap.data, heap.size);
}

int* sort(const struct _heap heap) {
	if (heap.size < 1) return nullptr;
	int *arr = new int[heap.size];

	for (int i = 0; i < heap.size; i++) {
		arr[i] = heap.data[i];
	}

	for (int i = heap.size - 1; i > 0; i--) {
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;

		heapify(arr, i, 0);
	}

	return arr;

}

void clear_heap(struct _heap &heap) {
	delete(heap.data);
	heap.data = nullptr;
	heap.size = -1;
	heap.max_size = -1;
	heap.buf_size = -1;
}

void heapify(int* arr, int len, int pos) {
	int l = left(pos);
	int r = right(pos);
	int largest = 0;

	if (l < len && arr[l] > arr[pos]) {
		largest = l;
	}
	else {
		largest = pos;
	}

	if (r < len && arr[r] > arr[largest]) {
		largest = r;
	}

	if (largest != pos) {
		int tmp = arr[largest];
		arr[largest] = arr[pos];
		arr[pos] = tmp;
		heapify(arr, len, largest);
	}
}

void build_heap(int* arr, int len) {
	for (int i = parent(len - 1); i >= 0; i--) {
		heapify(arr, len, i);
	}
}

void heap_sort(int *arr, int len) {
	build_heap(arr, len);

	for (int i = len - 1; i > 0; i--) {
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;

		heapify(arr, i, 0);
	}
}

int left(int pos) {
	return pos * 2 + 1;
}

int right(int pos) {
	return pos * 2 + 2;
}

int parent(int pos) {
	return (pos-1) / 2;
}

int calc_buf_size(const int size, const int max_size) {
	if (size + BUF_SIZE_STEP < max_size) return size + BUF_SIZE_STEP;
	else return max_size;
}