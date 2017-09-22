#include"binary_indexed_tree.h"
#include<stdlib.h>
#include<string.h>

struct _BINARY_INDEXED_TREE init_binary_indexed_tree(const int* arr, const int size) {
	struct _BINARY_INDEXED_TREE tree;
	tree.tree = (int*)calloc(size, sizeof(int));
	tree.length = size;

	for (int i = 0; i < size; i++) {
		add(tree, i, arr[i]);
	}

	tree.source = (int*)calloc(size, sizeof(int));
	memcpy(tree.source, arr, size*sizeof(int));

	return tree;
}

int sum(const struct _BINARY_INDEXED_TREE tree, const int idx) {
	int tree_idx = idx;
	int tree_pos = idx + 1;

	int sum = 0;
	while (tree_idx >= 0) {
		sum += tree.tree[tree_idx];
		tree_pos -= (tree_pos & -tree_pos);
		tree_idx = tree_pos - 1;
	}

	return sum;
}

void add(const struct _BINARY_INDEXED_TREE tree, const int idx, const int addval) {
	int tree_idx = idx;
	int tree_pos = idx + 1;

	while (tree_idx < tree.length) {
		tree.tree[tree_idx] += addval;
		tree_pos += (tree_pos & -tree_pos);
		tree_idx = tree_pos - 1;
	}
}

int read(const struct _BINARY_INDEXED_TREE tree, const int left, const int right) {
	if (left == 0) { return sum(tree, right); }
	return sum(tree, right) - sum(tree, left-1);
}

void update(const struct _BINARY_INDEXED_TREE tree, const int idx, const int data) {
	add(tree, idx, data - tree.source[idx]);
}

void remove_binary_indexed_tree(struct _BINARY_INDEXED_TREE tree) {
	free(tree.source);
	free(tree.tree);
	tree.source = nullptr;
	tree.tree = nullptr;
	tree.length = 0;
}