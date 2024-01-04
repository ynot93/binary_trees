#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: Depth of the node or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - Finds lowest common ancestor of 2 nodes.
 * @first: Pointer to first node.
 * @second: Pointer to second node.
 *
 * Return: Pointer to lowest common ancestor node, or NULL
 *         if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}

	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}

	while (first != NULL && second != NULL && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	if (first == NULL || second == NULL)
		return (NULL);
	return (binary_tree_t *)(first);
}
