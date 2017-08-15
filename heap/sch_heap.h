#define BUF_SIZE_STEP 5

struct _heap {
	int size = -1;
	int buf_size = -1;
	int max_size = -1;
	int* data;
};

struct _heap create_heap(const int MAX_SIZE);
struct _heap create_heap(const int* arr, const int len, const int MAX_SIZE);
int get_value(const struct _heap heap, const int pos);
void set_value(struct _heap &heap, const int pos, const int value);
void add_value(struct _heap &heap, const int value);
void add_values(struct _heap &heap, const int* values, const int len);
int* sort(const struct _heap heap);
void clear_heap(struct _heap &heap);

void heapify(int* arr, int len, int pos);
void build_heap(int *arr, int len);
void heap_sort(int *arr, int len);
int left(int pos);
int right(int pos);
int parent(int pos);

int calc_buf_size(const int size, const int max_size);