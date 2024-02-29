#include "binary_trees.h"

/**
 * binary_tree_delete - This will delete a binary tree.
 *
 * @tree: pointer to the root node of the tree to delete.
 *
 * Description: Recursively deletes each node of the binary tree starting
 * from the given root node and frees memory allocated for each node.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		/* Delete the left subtree */
		binary_tree_delete(tree->left);

		/* Delete the right subtree */
		binary_tree_delete(tree->right);
		free(tree);
	}
}
