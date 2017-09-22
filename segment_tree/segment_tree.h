struct _SEGTREE {
	int* tree;
	int size;
	int length;
};

struct _SEGTREE init_segment_tree(const int* arr, const int size);
int read(const struct _SEGTREE tree, const int left, const int right);
void update(struct _SEGTREE tree, const int idx, int data);

typedef struct _SEGTREE Segtree;