struct _BINARY_INDEXED_TREE {
	int* tree;
	int* source;
	int length;
};

struct _BINARY_INDEXED_TREE init_binary_indexed_tree(const int* arr, const int size);
int sum(const struct _BINARY_INDEXED_TREE tree, const int idx);
void add(const struct _BINARY_INDEXED_TREE tree, const int idx, const int addval);
int read(const struct _BINARY_INDEXED_TREE tree, const int left, const int right);
void update(const struct _BINARY_INDEXED_TREE tree, const int idx, const int data);
void remove_binary_indexed_tree(struct _BINARY_INDEXED_TREE tree);

typedef struct _BINARY_INDEXED_TREE binary_indexed_tree;