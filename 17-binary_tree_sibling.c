#include "binary_trees.h"

/**
 * binary_tree_sibling - Func finds the sibling
 * of a node in a binary tree.
 *
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling (NULL)
 * Else (Pointer to the sibling)
 *
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If node is NULL or has no parent, it has no sibling */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, return the right child of its parent */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, return the left child of its parent */
	return (node->parent->left);
}
