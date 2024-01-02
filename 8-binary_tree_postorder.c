#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree the postorder way.
 * @tree: Pointer toth e root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);

	binary_tree_postorder(tree->right, func);

	func(tree->n);
}
