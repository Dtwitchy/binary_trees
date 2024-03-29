#include "binary_trees.h"

/**
 * binary_tree_leaves - This func will count
 * the leaves in a binary tree
 *
 * @tree: Just a pointer to the root node of
 * the tree to count the leaves of
 *
 * Return: The number of leaves in the tree
 *
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		/* If the tree has no children, it's a leaf */
		leaves += (!tree->left && !tree->right) ? 1 : 0;

		/* Recursively count leaves in the left and right subtree */
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
