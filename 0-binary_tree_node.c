#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node for a binary tree.
 *
 * @parent: Pointer to the parent node to create.
 *
 * @value: value to put in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 *
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_n;

	/* Allocate memory for the new node */
	new_n = malloc(sizeof(binary_tree_t));
	if (new_n == NULL)
		return (NULL);

	new_n->n = value;
	new_n->parent = parent;
	new_n->left = NULL;
	new_n->right = NULL;

	return (new_n);
}
