#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: Pointer to the node to find sibling.
 * 
 * Return: Pointer to sibling or NULL if no sibling node
 *         or parent.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return (node->parent->left);
	else
		return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: Pointer to the node to find sibling.
 *
 * Return: Pointer to uncle or NULL if no uncle or node
 *         is NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
