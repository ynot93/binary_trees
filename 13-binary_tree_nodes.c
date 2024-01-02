#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least one child
 *                     in a binary tree.
 * @tree: Pointer to root node of tree.
 *
 * Return: Number of nodes or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t l_count, r_count;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		l_count = binary_tree_nodes(tree->left);

		r_count = binary_tree_nodes(tree->right);

		return (1 + l_count + r_count);
	}

	return (0);
}
