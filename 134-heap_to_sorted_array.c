#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t i, array_size;

	if (!heap || !size)
	return (NULL);

	array_size = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * array_size);
	if (!sorted_array)
	return (NULL);

	for (i = 0; i < array_size; ++i)
	sorted_array[i] = heap_extract(&heap);

	*size = array_size;
	return (sorted_array);
}
