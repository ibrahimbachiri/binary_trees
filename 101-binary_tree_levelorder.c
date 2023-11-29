#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to the function to call for each node. The node's value
 *        must be passed as a parameter to this function.
 *
 * Description: This function traverses the binary tree in level-order,
 *              visiting each level from left to right.
 *              If tree or func is NULL, the function does nothing.
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
