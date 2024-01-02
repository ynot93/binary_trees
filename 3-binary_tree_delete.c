#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes the entire binary tree.
 * @tree: Pointe to the rrot node o the tree to delete.
 *
 * Return - Nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);

	binary_tree_delete(tree->right);

	free(tree);
}
