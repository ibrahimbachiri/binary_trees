#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the desired
 * value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
	root->left = avl_remove(root->left, value);
	else if (value > root->n)
	root->right = avl_remove(root->right, value);
	else
	{
	if (root->left == NULL || root->right == NULL)
	{
	avl_t *temp = root->left ? root->left : root->right;

	if (temp == NULL)
	{
	temp = root;
	root = NULL;
	}
	else
	*root = *temp; /* Copy the contents of temp to root */
            
	free(temp);
	}
	else
	{
	avl_t *temp = binary_tree_minimum(root->right);

	root->n = temp->n;
	root->right = avl_remove(root->right, temp->n);
	}
	}

	if (root == NULL)
	return NULL;

	root->height = 1 + MAX(binary_tree_height(root->left), binary_tree_height(root->right));

	int balance = binary_tree_balance(root);

	/* Left Heavy */
	if (balance > 1)
	{
	/* Left-Right Heavy */
	if (binary_tree_balance(root->left) < 0)
	root->left = binary_tree_rotate_left(root->left);

	return binary_tree_rotate_right(root);
	}

	/* Right Heavy */
	if (balance < -1)
	{
	/* Right-Left Heavy */
 	if (binary_tree_balance(root->right) > 0)
	root->right = binary_tree_rotate_right(root->right);

	return binary_tree_rotate_left(root);
	}

	return root;
}
