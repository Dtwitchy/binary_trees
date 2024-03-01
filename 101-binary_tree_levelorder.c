#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void dad(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - This func only creates
 * a new level order_queue_t node.
 *
 * @node: Binary tree node for the new node to contain.
 *
 * Return: If an error (NULL) Else, (Pointer to the new node)
 *
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_n;

	new_n = malloc(sizeof(levelorder_queue_t));
	if (new_n == NULL)
		return (NULL);

	new_n->node = node;
	new_n->next = NULL;

	return (new_n);
}

/**
 * free_queue - Func that frees a level order_queue_t queue.
 *
 * @head: Pointer to head of queue
 *
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - this will run a func on a given binary tree
 * node and push children into a level order_queue_t queue
 *
 * @node: Binary tree node to print and push
 *
 * @head: Double pointer to the head of the queue
 *
 * @tail: Double pointer to the tail of the queue
 *
 * @func: Pointer to the func to call on @node.
 *
 * Description: Upon malloc failure, exit (status code = 1)
 *
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_n;

	func(node->n);
	if (node->left != NULL)
	{
		new_n = create_node(node->left);
		if (new_n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_n;
		*tail = new_n;
	}
	if (node->right != NULL)
	{
		new_n = create_node(node->right);
		if (new_n == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_n;
		*tail = new_n;
	}
}

/**
 * dad - This func dads the head of a level order_queue_t queue
 *
 * @head: Pointer to the pointer to the head of the queue.
 *
 */

void dad(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - This will traverse a
 * binary tree using alevel-order traversal
 *
 * @tree: Pointer to root node of the tree to traverse
 *
 * @func: Pointer to function to call for each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		dad(&head);
	}
}
