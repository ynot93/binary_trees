#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures size of a binary tree.
 * @tree: Pointer of tree to be measured.
 *
 * Return: size of tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_size, r_size;

	if (tree == NULL)
		return (0);

	l_size = binary_tree_size(tree->left);

	r_size = binary_tree_size(tree->right);

	return (1 + r_size + l_size);
}

/**
 * binary_tree_levelorder - Goes through a binary tree through
 * level order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to function to call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int first = 0, second = 0;
	binary_tree_t **queue;

	if (tree == NULL || func == NULL)
		return;

	/* Use queue for level order traversal */
	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return;

	queue[second] = (binary_tree_t *)tree;
	second++;

	while (first < second)
	{
		binary_tree_t *current = queue[first];
		first++;

		func(current->n);

		if (current->left != NULL)
		{
			queue[second] = current->left;
			second++;
		}

		if (current->right != NULL)
		{
			queue[second] = current->right;
			second++;
		}
	}
	free(queue);
}
