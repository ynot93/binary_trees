#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures size of a binary tree.
 * @tree: Pointer of tree to be measured.
 *
 * Return: size of tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_size, r_size;

	if (tree == NULL)
		return (0);

	l_size = binary_tree_size(tree->left);

	r_size = binary_tree_size(tree->right);

	return (1 + r_size + l_size);
}

/**
 * binary_tree_is_complete - Checks if binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete_recursive(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete_recursive - helper function for checking completeness.
 * @tree: Pointer to the current node.
 * @index: Index of the current node.
 * @count: Total number of nodes.
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	if (is_complete_recursive(tree->left, 2 * index + 1, count) &&
		is_complete_recursive(tree->right, 2 * index + 2, count))
		return (1);
	return (0);
}
