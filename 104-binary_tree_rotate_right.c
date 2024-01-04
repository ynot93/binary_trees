#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root, *pivot;

    if (tree == NULL || tree->left == NULL)
        return (NULL);

    pivot = tree->left;
    new_root = pivot;
    tree->left = pivot->right;

    if (pivot->right != NULL)
        pivot->right->parent = tree;

    pivot->right = tree;
    tree->parent = pivot;
    pivot->parent = NULL;

    return (new_root);
}

