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

	/* return the right child of its grandp if p of node is left */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* return the left child of its grandp if p of node is right */
	return (node->parent->parent->left);
}
