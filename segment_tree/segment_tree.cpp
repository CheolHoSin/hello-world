#include "segment_tree.h"
#include <stdlib.h>
#include <string.h>

struct _SEGTREE init_segment_tree(const int* arr, const int size) {
	struct _SEGTREE tree;
	tree.size = 2*size-1;
	tree.length = size;
	tree.tree = (int*)calloc(2*size, sizeof(int));

	for (int i = 0; i < size; i++) {
		update(tree, i, arr[i]);
	}

	return tree;
}

int query(const struct _SEGTREE tree, const int left, const int right, const int segment_left, const int segment_right, const int node_idx) {
	if (segment_right < left || segment_left > right) return 0;

	if (segment_left >= left && segment_right <= right) return tree.tree[node_idx];

	int mid = (segment_left + segment_right) / 2;

	return query(tree, left, right, segment_left, mid, node_idx * 2 + 1)
		+ query(tree, left, right, mid + 1, segment_right, node_idx * 2 + 2);
}

int read(const struct _SEGTREE tree, const int left, const int right) {
	return query(tree, left, right, 0, tree.length-1, 0);
}

void update(struct _SEGTREE tree, const int idx, int data) {
	int tree_idx = idx + tree.length - 1;
	tree.tree[tree_idx] = data;

	while (tree_idx > 0) {
		tree_idx = (tree_idx-1) / 2;

		tree.tree[tree_idx] = tree.tree[tree_idx * 2 + 1] + tree.tree[tree_idx * 2 + 2];
	}
}