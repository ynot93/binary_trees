#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root, *pivot;

    if (tree == NULL || tree->right == NULL)
        return (NULL);

    pivot = tree->right;
    new_root = pivot;
    tree->right = pivot->left;

    if (pivot->left != NULL)
        pivot->left->parent = tree;

    pivot->left = tree;
    tree->parent = pivot;
    pivot->parent = NULL;

    return (new_root);
}

