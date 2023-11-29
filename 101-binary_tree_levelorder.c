#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree in level order.
 * @tree: A pointer to the root node.
 * @func: A pointer to a function to call for each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *node;
	int height, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	for (level = 1; level <= height + 1; level++)
	binary_tree_traverse(tree, func, level);
}