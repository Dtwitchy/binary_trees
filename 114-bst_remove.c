#include "binary_trees.h"

/**
 * find_node - Finds a node with a given value in a binary search tree.
 * @root: The root of the binary search tree.
 * @value: The value of the node.
 * @just like bst_search function (task 113)
 * Return: A pointer to the found node, otherwise NULL.
 */
bst_t *find_node(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (root != NULL)
	{
		if (root->left != NULL)
			node = root->left->parent;
		if ((node == NULL) && (root->right != NULL))
			node = root->right->parent;
		while (node != NULL)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * replace_with_successor - Replaces a node with its inorder \
 * successor in a binary search tree.
 * @node: A pointer to the node in the binary search tree.
 *
 * Return: A pointer to the node's inorder successor node.
 */
bst_t *replace_with_successor(bst_t **node)
{
	bst_t *new_n;

	new_n = (*node)->right;
	while ((new_n != NULL) && (new_n->left != NULL))
		new_n = new_n->left;
	if ((new_n != NULL) && (new_n == (*node)->right))
	{
		new_n->parent = (*node)->parent;
		new_n->left = (*node)->left;
		if ((*node)->left != NULL)
			(*node)->left->parent = new_n;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = new_n;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = new_n;
		}
	}
	else if (new_n != NULL)
	{
		new_n->parent->left = new_n->right;
		if (new_n->right != NULL)
			new_n->right->parent = new_n->parent;
		new_n->parent = (*node)->parent;
		new_n->left = (*node)->left;
		new_n->right = (*node)->right;
		(*node)->left->parent = new_n;
		(*node)->right->parent = new_n;
		if ((*node)->parent != NULL)
		{
			if ((*node)->parent->left == *node)
				(*node)->parent->left = new_n;
			if ((*node)->parent->right == *node)
				(*node)->parent->right = new_n;
		}
	}
	return (new_n);
}

/**
 * bst_remove - Removes a node with a given value in a binary search tree.
 * @root: The binary search tree.
 * @value: The value of the node.
 *
 * Return: A pointer to the tree's root node, otherwise NULL.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *new_r = root, *new_n = NULL;

	if (new_r != NULL)
	{
		node = find_node(root, value);
		if ((node != NULL) && (node->n == value))
		{
			if ((node->left == NULL) && (node->right == NULL))
			{
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = NULL;
					if (node->parent->right == node)
						node->parent->right = NULL;
				}
			}
			else if ((node->left != NULL) ^ (node->right != NULL))
			{
				new_n = (node->left != NULL ? node->left : node->right);
				if (node->parent != NULL)
				{
					if (node->parent->left == node)
						node->parent->left = new_n;
					else if (node->parent->right == node)
						node->parent->right = new_n;
				}
				new_n->parent = node->parent;
			}
			else
			{
				new_n = replace_with_successor(&node);
			}
			new_r = (node->parent == NULL ? new_n : root);
			free(node);
		}
	}
	return (new_r);
}
