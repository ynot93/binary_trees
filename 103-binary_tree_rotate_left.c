#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs left rotation.
 * @tree: Pointer to root node of the tree.
 *
 * Return: Pointer to new root node of rotated tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left != NULL)
		new_root->left->parent = tree;

	new_root->parent = tree->parent;

	if (tree->parent == NULL)
		new_root = tree;
	else if (tree == tree->parent->left)
		tree->parent->left = new_root;
	else
		tree->parent->right = new_root;

	new_root->left = tree;
	tree->parent = new_root;

	return new_root;
}
