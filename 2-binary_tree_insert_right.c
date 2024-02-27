#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as
 * the right child of a given node.
 *
 * @parent: Pointer to the node to insert the right-child in.
 *
 * @value: Value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs (NULL).
 * Else pointer to the new node.
 *
 * Description: If parent already has a right-child,
 * the new node takes its place and the old right-child
 * is set as the right-child of new node.
 *
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	/* Check if the parent node is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new node with the given value */
	new_n = binary_tree_node(parent, value);
	if (new_n == NULL)
		return (NULL);

	/* If the parent already has a right child */
	if (parent->right != NULL)
	{
		new_n->right = parent->right;
		parent->right->parent = new_n;
	}
	parent->right = new_n;

	return (new_n);
}
