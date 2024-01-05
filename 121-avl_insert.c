#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root of the AVL tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the created node,
 *         or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;

	if (tree == NULL)
		return NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
	}
	else
	{
		return (*tree);
	}

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * max - Returns the maximum of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: The max value of a and b.
 */
int max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}
