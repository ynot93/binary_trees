#include "binary_trees.h"

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
