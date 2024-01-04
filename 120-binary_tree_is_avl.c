#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

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
 * binary_tree_is_avl - Checks if binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_tree(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_tree - Checks if binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum allowed value for a node.
 * @max: Maximum allowed value for a node.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int is_avl_tree(const binary_tree_t *tree, int min, int max)
{
	int l_height, r_height, balance;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	l_height = binary_tree_height(tree->left);

	r_height = binary_tree_height(tree->right);

	if (abs(l_height - r_height) > 1)
		return (0);

	balance = is_avl_tree(tree->left, min, tree->n) &&
			  is_avl_tree(tree->right, tree->n, max);

	return (balance);
}
