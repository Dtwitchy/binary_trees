#include "binary_trees.h"

/**
 * binary_tree_depth - Func measures the depth
 * of a node in a binary tree
 *
 * @tree: Just a pointer
 *
 * Return: If tree is NULL (0), else (depth)
 *
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* If the node is NULL or has no parent, return 0 */
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
