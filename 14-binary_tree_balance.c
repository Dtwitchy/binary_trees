#include "binary_trees.h"

/**
 * binary_tree_balance - func measures the balance
 * factor of a binary tree
 *
 * @tree: Just a pointer
 *
 * Return: If tree is NULL, (0 )else (balance factor)
 *
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	/* If the tree is empty, return 0 */
	if (tree == NULL)
		return (0);

	/* Calculate the balance factor */
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - To measure the height of a binary tree
 *
 * @tree: Just a pointer
 *
 * Return: If tree is NULL (0) else (height)
 *
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft_h = 0, rgt_h = 0;

		lft_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rgt_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lft_h > rgt_h) ? lft_h : rgt_h);
	}
	return (0);
}
