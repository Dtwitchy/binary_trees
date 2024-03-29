#include "binary_trees.h"

/**
 * binary_tree_postorder - This func will traverse a
 * binary tree using post-order traversal
 *
 * @tree: Just a pointer
 *
 * @func: Just a pointer to a function to call for each node.
 *
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		/* Recursively traverse the left and right subtree */
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
