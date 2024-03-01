#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Description: If a value of the array already exists, this value is ignored
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t d;

	for (d = 0; d < size; d++)
	{
		bst_insert(&root, array[d]);
	}
	return (root);
}
