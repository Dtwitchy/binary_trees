#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as
 * the left child of a given node.
 *
 * @parent: Pointer to the node to insert the left-child in.
 *
 * @value: Value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs(NULL)
 * Else - a pointer to the new node.
 *
 * Description: If parent already has a left-child,
 * the new node takes its place and the old
 * left-child is set as the left-child of the new node.
 *
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	/* Check if the parent node is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new node with the given value */
	new_n = binary_tree_node(parent, value);
	if (new_n == NULL)
		return (NULL);

	/* If the parent already has a left child */
	if (parent->left != NULL)
	{
		new_n->left = parent->left;
		parent->left->parent = new_n;
	}
	parent->left = new_n;

	return (new_n);
}
