#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_remove - Removes a node from a BST.
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove.
 *
 * Return: Pointer to the new root node of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * find_min - Finds the minimum value node in a BST
 * @node: Pointer to the root node of the BST
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}
