#include "binary_trees.h"

/**
 * binary_trees_ancestor - Func that finds the
 * lowest common ancestor of two nodes.
 *
 * @first: pointer to first node.
 *
 * @second: Just apointer to second node.
 *
 * Return: If no common ancestors (NULL), else (common ancestor)
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *dad;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent, dad = second->parent;
	if (first == dad || !mom || (!mom->parent && dad))
		return (binary_trees_ancestor(first, dad));
	else if (mom == second || !dad || (!dad->parent && mom))
		return (binary_trees_ancestor(mom, second));
	return (binary_trees_ancestor(mom, dad));
}
