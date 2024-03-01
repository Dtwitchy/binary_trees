#include "binary_trees.h"

/**
 * is_full_recursive - This func checks if a
 * binary tree is full recursively
 *
 * @tree: Pointer to root node of the tree to check.
 *
 * Return: If tree is not full (0) Else (1)
 *
 */

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Func that checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full or NULL, 0 otherwise.
 *
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If the tree is NULL, it's not full */
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
