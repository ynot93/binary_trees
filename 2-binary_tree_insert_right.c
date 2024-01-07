#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts node as right child of node.
 * @parent - Pointer to the parent node.
 * @value - Value to put in the new node.
 *
 * Return - Pointer to the new node or NULL when it fails
 * or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
