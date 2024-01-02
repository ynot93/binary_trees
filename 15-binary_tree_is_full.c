#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node to check.
 *
 * Return: 1 if tree is full, 0 if not or tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_full, r_full;

	if (tree == NULL)
		return (1);

	if ((tree->left == NULL && tree->right == NULL) ||
	    (tree->right != NULL && tree->left != NULL))
	{
		l_full = binary_tree_is_full(tree->left);
		r_full = binary_tree_is_full(tree->right);

		return (l_full && r_full);
	}

	return (0);
}
