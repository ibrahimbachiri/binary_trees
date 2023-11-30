#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value from a Max Binary Heap
 * @root: Pointer to the root node of the heap
 * Return: The extracted value
 */
int heap_extract(heap_t **root)
{
    int extracted_value;

    if (!root || !*root)
        return 0;

    extracted_value = (*root)->n;

    // Replace the root value with the last node's value
    (*root)->n = heap_remove_last(root);

    // Rebalance the heap
    heapify_down(*root);

    return extracted_value;
}

/**
 * heap_remove_last - Removes the last node from the heap
 * @root: Pointer to the root node of the heap
 * Return: The value of the removed node
 */
int heap_remove_last(heap_t **root)
{
    int last_value;
    heap_t *last_node;

    last_node = binary_tree_get_last(*root);
    if (!last_node)
        return 0;

    last_value = last_node->n;

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);

    return last_value;
}

/**
 * binary_tree_get_last - Gets the last node in a binary tree
 * @root: Pointer to the root node of the tree
 * Return: Pointer to the last node
 */
heap_t *binary_tree_get_last(heap_t *root)
{
    if (!root)
        return NULL;

    while (root->left || root->right)
    {
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }

    return root;
}

/**
 * heapify_down - Rebalances the Max Binary Heap after extraction
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *max_node, *temp;

    if (!root)
        return;

    max_node = root;

    while (1)
    {
        if (max_node->left && max_node->left->n > max_node->n)
            temp = max_node->left;
        else
            temp = max_node;

        if (max_node->right && max_node->right->n > temp->n)
            temp = max_node->right;

        if (temp == max_node)
            break;

        swap_values(&max_node->n, &temp->n);
        max_node = temp;
    }
}

/**
 * swap_values - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_values(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
