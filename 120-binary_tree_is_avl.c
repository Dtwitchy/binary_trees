#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @sln: The value of the smallest node visited thus far.
 * @lgn: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int sln, int lgn)
{
	size_t lgt, rgt, diff;

	if (tree != NULL)
	{
		if (tree->n < sln || tree->n > lgn)
			return (0);
		lgt = height(tree->left);
		rgt = height(tree->right);
		diff = lgt > rgt ? lgt - rgt : rgt - lgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, sln, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, lgn));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
