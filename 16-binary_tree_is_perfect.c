#include "binary_trees.h"

/**
 * binary_tree_height - Measures height of a binary tree.
 * @tree: Pointer of tree to be measured.
 *
 * Return: height of tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);

	r_height = binary_tree_height(tree->right);

	if (l_height > r_height)
		return (1 + l_height);
	return (1 + r_height);
}

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
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is perfect and 0 if it is not or tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	size = binary_tree_size(tree);

	if (size == (1 << height) - 1)
		return (1);
	return (0);
}
