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
 * binary_tree_balance - Measures binary factor of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: balance factor or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);

	r_height = binary_tree_height(tree->right);

	return (int)(l_height - r_height);
}
