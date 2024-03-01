#include "binary_trees.h"

/**
 * _sorted_array_to_avl - helper func for sorted_array_to_avl
 * @array: input array
 * @start: starting index
 * @end: ending index
 * @parent: pointer to parent node
 * Return: newly created node
 */
avl_t *_sorted_array_to_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_n;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	new_n = calloc(1, sizeof(avl_t));
	if (!new_n)
		return (NULL);
	new_n->n = array[mid];
	new_n->parent = parent;
	new_n->left = _sorted_array_to_avl(array, start, mid - 1, new_n);
	new_n->right = _sorted_array_to_avl(array, mid + 1, end, new_n);
	return (new_n);
}


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: input array
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (!array)
		return (NULL);
	return (_sorted_array_to_avl(array, 0, size - 1, NULL));
}
