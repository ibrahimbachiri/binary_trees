#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

/* Basic binary tree structure*/
typedef struct binary_tree_s binary_tree_t;
typedef struct bst_node_s bst_t;

struct bst_node_s
{
    int n;
    struct bst_node_s *parent;
    struct bst_node_s *left;
    struct bst_node_s *right;
};

typedef struct avl_tree_s {
    int n;
    struct avl_tree_s *parent;
    struct avl_tree_s *left;
    struct avl_tree_s *right;
    int height;
	size_t height;
} avl_t;

typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
    struct binary_tree_s *parent;
} binary_tree_t;

/* AVL Tree Structure */
typedef struct binary_tree_s avl_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
int is_complete_util(const binary_tree_t *tree, int index, int nodes_count);
size_t binary_tree_size(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_util(const binary_tree_t *tree, int min, int max);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree, size_t size, size_t index);
int is_max_heap(const binary_tree_t *tree);
#endif /* BINARY_TREES_H */
