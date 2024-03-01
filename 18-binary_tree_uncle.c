#include "binary_trees.h"

/**
 * binary_tree_uncle - Func that finds the
 * uncle of a node in a binary tree.
 *
 * @node: Pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no uncle (NULL)
 * Else (pointer to the uncle node)
 *
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* If node is NULL or has no parent or grandparent, it has no uncle */
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	/* If the parent of node is a left child, return the right child of its grandparent */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* If the parent of node is a right child, return the left child of its grandparent */
	return (node->parent->parent->left);
}
